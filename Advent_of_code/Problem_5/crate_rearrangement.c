/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   crate_rearrangement.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:18:10 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/09 14:58:40 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char	*crate_rearrangement_stack_result(char *text);
char	**assign_stack_contents(char **stacks);
char 	**rearrange_boxes(char **stacks, char *text);
char	**get_new_stack_arrangement(char **stacks, int move_amount, int src_stack_num, int dst_stack_num);

char	*crate_rearrangement_stack_result(char *text)
{
	int		i;
	char	*result_string;
	char	**stacks;

	i = 0;
	result_string = calloc(9, sizeof(char));
	stacks = (char **)calloc(9, sizeof(char *));
	if (result_string == NULL || stacks == NULL)
		return (NULL);
	while (i <= 9)
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
	printf("Assigned stack contents successfully.\n");
	stacks = rearrange_boxes(stacks, text);
	return (result_string);
}

char	**assign_stack_contents(char **stacks)
{
	stacks[0] = "FDBZTJRN";
	stacks[1] = "RSNJH";
	stacks[2] = "CRNJGZFQ";
	stacks[3] = "FVNGRTQ";
	stacks[4] = "LTQF";
	stacks[5] = "QCWZBRGN";
	stacks[6] = "FCLSNHM";
	stacks[7] = "DNQMTJ";
	stacks[8] = "PGS";
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
	while (text[i] != '\n' && text[i + 1] != '\n')
	{
		if ((text[i] >= '0') && (text[i] <= '9'))
			i++;
		printf("i is set to %c before the loop\n", text[i]);
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
			printf("i is set to %c\n", text[i]);
			while (text[i] != ' ')
			{
				src_stack_num = src_stack_num + (text[i] - 48);
				if (text[i + 1] != ' ')
					src_stack_num = src_stack_num * 10;
				i++;
				printf("The source stack is: %i.\n", src_stack_num);
			}
			i = i + 4;
			printf("i is set to %c\n", text[i]);
			while (text[i] != '\n')
			{
				dst_stack_num = dst_stack_num + (text[i] - 48);
				if (text[i + 1] != ' ')
					dst_stack_num = dst_stack_num * 10;
				i++;
				printf("The destination stack is: %i.\n", dst_stack_num);
			}
			stacks = get_new_stack_arrangement(stacks, move_amount, src_stack_num, dst_stack_num);
		}//end of instruction line.
		printf("Successfully applied 1 line of instructions.\n");
	}//end of all instruction lines.
	return (stacks);
}

char	**get_new_stack_arrangement(char **stacks, int move_amount, int src_stack_num, int dst_stack_num)
{
	int src_stack_strlen;
	int	dst_stack_strlen;

	move_amount = move_amount + 1;
	move_amount = move_amount - 1;
	src_stack_strlen = (int)strlen(stacks[src_stack_num - 1]);
	dst_stack_strlen = (int)strlen(stacks[dst_stack_num - 1]);
	printf("moving %i amount of crates from stack %i to stack %i.\n", move_amount, src_stack_num, dst_stack_num);
	while (move_amount > 0)
	{
		stacks[src_stack_num - 1][src_stack_strlen] = stacks[src_stack_num - 1][dst_stack_strlen];
		stacks[src_stack_num - 1][src_stack_strlen] = '\0';
		src_stack_strlen--;
		dst_stack_strlen++;
		move_amount--;
	}
	printf("Move successful. (:\n");
	return (stacks);
}

int main(void)
{
	char	*answer;
	FILE	*problem_5_check;
	char	*text;
	long	numbytes;
	
	problem_5_check = fopen("problem_5_check.txt", "r");
	if(problem_5_check == NULL)
		return (0);
		
	fseek(problem_5_check, 0L, SEEK_END);
	numbytes = ftell(problem_5_check);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_5_check, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_5_check);
	fclose(problem_5_check);
	
	answer = crate_rearrangement_stack_result(text);
	printf("The total number of redundant assignments is: %s\n", answer); 
	return(0);
}