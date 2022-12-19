/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   crate_rearrangement9001.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:18:10 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/15 13:54:07 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char	*crate_rearrangement_stack_result(char *text);
char	**assign_stack_contents(char **stacks);
char 	**rearrange_boxes(char **stacks, char *text);
char	**get_new_stack_arrangement(char **stacks, int move_amount, int src_stack_num, int dst_stack_num);
char	*get_last_box(char **stacks, char *result_string);
char	**multiple_crate_arrangement(char **stacks, int move_amount, int src_stack_num, int dst_stack_num);

char	*crate_rearrangement_stack_result(char *text)
{
	int		i;
	char	**stacks;
	char 	*result_string;
	
	i = 0;
	result_string = (char *)calloc(20, sizeof(char));
	strcpy(result_string, "00000000");
	printf("result string contains: %s\n", result_string);
	stacks = (char **)calloc(9, sizeof(char *));
	if (stacks == NULL || result_string == NULL)
		return (NULL);
	while (i <= 8)
	{
		stacks[i] = (char *)calloc(57, sizeof(char));
		if (stacks[i] == NULL)
		{
			while (i >= 0)
			{
				free(stacks[i]);
				i--;
			}
			free(stacks);
			return (NULL);
		}
		i++;
	}
	stacks = assign_stack_contents(stacks);
	printf("Assigned stack contents successfully.\n\n");
	stacks = rearrange_boxes(stacks, text);
	printf("arrived back at main function\n");
	i = 0;
	while (i <= 9)
	{
		printf("stack %i: %s.\n", (i + 1), stacks[i]);
		i++;
	}
	get_last_box(stacks, result_string);
	return (result_string);
}

char	**assign_stack_contents(char **stacks)
{
	strcpy(stacks[0], "FDBZTJRN\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[1], "RSNJH\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[2], "CRNJGZFQ\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[3], "FVNGRTQ\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[4], "LTQF\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[5], "QCWZBRGN\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[6], "FCLSNHM\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[7], "DNQMTJ\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	strcpy(stacks[8], "PGS\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	return (stacks);
}

char **rearrange_boxes(char **stacks, char *text)
{
	int		i;
	int		move_amount;
	int		src_stack_num;
	int		dst_stack_num;
	
	i = 0;
	move_amount = 0;
	src_stack_num = 0;
	dst_stack_num = 0;
	while (text[i] != '~')
	{
		while (!((text[i] >= '0') && (text[i] <= '9')))
			i++;
		/* printf("i is set to %c before the loop\n", text[i]); */
		while (text[i] != '\n')
		{
			while (text[i] != ' ')
			{
				move_amount = move_amount + (text[i] - 48);
				if (text[i + 1] != ' ')
					move_amount = move_amount * 10;
				i++;
				printf("The move amount is: %i.\n", move_amount);
			}
			i = i + 6;
			/* printf("i is set to %c\n", text[i]); */
			while (text[i] != ' ')
			{
				src_stack_num = src_stack_num + (text[i] - 48);
				if (text[i + 1] != ' ')
					src_stack_num = src_stack_num * 10;
				i++;
/* 				printf("The source stack is: %i.\n", src_stack_num); */
			}
			i = i + 4;
			/* printf("i is set to %c\n", text[i]); */
			while (text[i] != '\n')
			{
				dst_stack_num = dst_stack_num + (text[i] - 48);
				if (text[i + 1] != '\n')
					dst_stack_num = dst_stack_num * 10;
				i++;
				/* printf("The destination stack is: %i.\n", dst_stack_num); */
			}
			if (move_amount == 1)
				stacks = get_new_stack_arrangement(stacks, move_amount, src_stack_num, dst_stack_num);
			else 
				stacks = multiple_crate_arrangement(stacks, move_amount, src_stack_num, dst_stack_num);
			move_amount = 0;
			src_stack_num = 0;
			dst_stack_num = 0;
			/* printf("i is set to %c\n", text[i]); */ 
		}//end of instruction line.
		/* printf("Successfully applied a line of instructions.\n\n"); */
		i++;
	}//end of all instruction lines.
	return (stacks);
}

char	**get_new_stack_arrangement(char **stacks, int move_amount, int src_stack_num, int dst_stack_num)
{
	int		src_stack_strlen;
	int		dst_stack_strlen;

	move_amount = move_amount + 1;
	move_amount = move_amount - 1;
	src_stack_strlen = (int)strlen(stacks[src_stack_num - 1]);
	dst_stack_strlen = (int)strlen(stacks[dst_stack_num - 1]);
	printf("moving %i amount of crates from stack %i to stack %i.\n", move_amount, src_stack_num, dst_stack_num);
	while (move_amount > 0)
	{
		printf("Trying to move '%c', ", stacks[src_stack_num - 1][src_stack_strlen - 1]);
		printf("from stack %i to stack %i\n", src_stack_num, dst_stack_num);
		
		stacks[dst_stack_num - 1][dst_stack_strlen] = stacks[src_stack_num - 1][src_stack_strlen - 1];
		stacks[src_stack_num - 1][src_stack_strlen - 1]= '\0';
		
		src_stack_strlen--;
		dst_stack_strlen++;
		move_amount--;
	}
	printf("Move successful. (:\n");
	printf("Stack %i after: %s\n", src_stack_num, stacks[src_stack_num - 1]);
	printf("Stack %i after: %s\n", dst_stack_num, stacks[dst_stack_num - 1]);
	return (stacks);
}

char	**multiple_crate_arrangement(char **stacks, int move_amount, int src_stack_num, int dst_stack_num)
{
	int		src_stack_strlen;
	int		dst_stack_strlen;
	int		i;
	int		i_dup;

	src_stack_strlen = (int)strlen(stacks[src_stack_num - 1]);
	dst_stack_strlen = (int)strlen(stacks[dst_stack_num - 1]);
	i = src_stack_strlen - move_amount;
	i_dup = i;
	printf("moving %i amount of crates from stack %i to stack %i.\n", move_amount, src_stack_num, dst_stack_num);
	while (stacks[src_stack_num - 1][i] != '\0')
	{
		stacks[dst_stack_num - 1][dst_stack_strlen] = stacks[src_stack_num - 1][i];
		
		dst_stack_strlen++;
		i++;
	}
	while (move_amount > 0)
	{
		stacks[src_stack_num - 1][src_stack_strlen - 1] = '\0';
		src_stack_strlen--;
		move_amount--;
	}
	printf("Move successful. (:\n");
	printf("Stack %i after: %s\n", src_stack_num, stacks[src_stack_num - 1]);
	printf("Stack %i after: %s\n", dst_stack_num, stacks[dst_stack_num - 1]);
	return (stacks);
}
char	*get_last_box(char **stacks, char *result_string)
{
	int 	i;
	int		strlen_stack;
	
	strlen_stack = 0;
	i = 0;
	while (i < 9)
	{
		strlen_stack = strlen(stacks[i]);
		printf("the final box is: %c\n", stacks[i][strlen_stack - 1]);
		result_string[i] = stacks[i][strlen_stack - 1];
		i++;
	}
	return (result_string);
}

int main(void)
{
	char	*answer;
	FILE	*problem_5_input;
	char	*text;
	long	numbytes;
	
	problem_5_input = fopen("problem_5_input.txt", "r");
	if(problem_5_input == NULL)
		return (0);
		
	fseek(problem_5_input, 0L, SEEK_END);
	numbytes = ftell(problem_5_input);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_5_input, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_5_input);
	fclose(problem_5_input);
	
	answer = crate_rearrangement_stack_result(text);
	printf("The result string is: %s\n", answer); 
	return(0);
}