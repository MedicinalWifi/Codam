/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   how_many_boxes_max.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:26:06 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/09 12:28:57 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int		crate_rearrangement_stack_result(char *text);

int		crate_rearrangement_stack_result(char *text)
{
	int		i;
	int		max_stack_height;
	int		*stacks;
	
	i = 0;
	max_stack_height = 0;
	stacks = malloc(9 * sizeof(int*));
	if (stacks == NULL)
		return (0);
	
	stack[1] = 8;
	stack[2] = 
	return (result_string);
}

int main(void)
{
	int		answer;
	FILE	*problem_4_input;
	char	*text;
	long	numbytes;
	
	problem_4_input = fopen("problem_4_input.txt", "r");
	if(problem_4_input == NULL)
		return (0);
		
	fseek(problem_4_input, 0L, SEEK_END);
	numbytes = ftell(problem_4_input);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_4_input, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_4_input);
	fclose(problem_4_input);
	
	answer = get_redundant_section_assignments_partial(text);
	printf("The total number of redundant assignments is: %i\n", answer); 
	return(0);
}