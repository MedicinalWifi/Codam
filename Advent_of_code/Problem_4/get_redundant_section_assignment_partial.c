/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_redundant_section_assignment_partial.c         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 12:44:31 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/09 12:18:03 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int		get_redundant_section_assignments(char *text);
int		get_start_section(char *text, int i);
int		get_end_section(char *text, int i);

int	get_redundant_section_assignments_partial(char *text)
{
	int	a1_start_section;
	int	a1_end_section;
	int	a2_start_section;
	int	a2_end_section;
	int	partial_containment_count;
	int	i;

	a1_start_section = 0;
	a2_end_section = 0;
	a1_start_section = 0;
	a2_end_section = 0;
	partial_containment_count = 0;
	i = 0;
	while (text[i] != '\n' && text[i + 1] != '\n')
	{
		printf("The whileloop started\n");
		
		a1_start_section = get_start_section(text, i);
		printf("The ID of elf1's startsection is: %i\n\n", a1_start_section);
		
		a1_end_section = get_end_section(text, i);
		printf("The ID of elf1's endsection is: %i\n\n", a1_end_section);
		
		while (text[i] != ',')
			i++;
		i++;
		
		a2_start_section = get_start_section(text, i);
		printf("The ID of elf2's startsection is: %i\n\n", a2_start_section);
		
		a2_end_section = get_end_section(text, i);
		printf("The ID of elf2's endsection is: %i\n\n", a2_end_section);
		
		if (a1_start_section <= a2_start_section && a1_end_section >= a2_start_section)
			partial_containment_count++;
		else if (a2_start_section <= a1_start_section && a2_end_section >= a1_start_section)
			partial_containment_count++;
		printf("full containment count is now: %i \n\n\n", partial_containment_count);
		
		while (text[i] != '\n')
			i++;
		i++;
	}
	return (partial_containment_count);
}

int	get_start_section(char *text, int i)
{
	int number;
	
	number = 0;
	while (text[i] != '-')
	{
		printf("the start section number is now: %i\n", number);
		number = number + (int)text[i] - 48;
		printf("the start section number is now: %i\n", number);
		if (text[i + 1] != '-')
			number = (number * 10);
		i++;
	}
	printf("before returning the number: %i\n", number);
	return (number);
}

int	get_end_section(char *text, int i)
{
	int number;
	
	number = 0;
	while (text[i] != '-')
		i++;
	i++;
	while (text[i] != ',' && text[i] != '\n')
	{
		printf("the end section number is now: %i\n", number);
		number = number + (int)text[i] - 48;
		printf("the end section number is now: %i\n", number);
		if (text[i + 1] != ',' && text[i + 1] != '\n')
			number = (number * 10);
		i++;
	}	
	return (number);
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