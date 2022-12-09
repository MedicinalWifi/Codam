/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Get_Rearrangement_Priorities.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 12:33:24 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/06 13:27:19 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 	get_sum_of_rearrangement_priorities(char *text);
int		get_package_len(char *text, int i);
char	get_wrong_item(char *text, int i, int package_len);
int		get_item_priority(char wrong_item);
int		get_item_priority(char wrong_item);

int get_sum_of_rearrangement_priorities(char *text)
{
	int		item_priority;
	int		priority_sum;
	int		package_len;
	int		i;
	char	wrong_item;

	item_priority = 0;
	priority_sum = 0;
	package_len = 0;
	i = 0;
	wrong_item = '.';
	while (text[i] != '\n')
	{
		package_len = get_package_len(text, i);
		printf("This package's Length is: %i\n", package_len);
		wrong_item = get_wrong_item(text, i, package_len);
		item_priority = get_item_priority(wrong_item);
		priority_sum += item_priority;
		i = (i + (package_len + 1));
		printf("i is now set to %c\n\n", ((int)text[i]));
	}
	return (priority_sum);
}

int	get_package_len(char *text, int i)
{
	int str_len;
	
	str_len = 0;
	while (text[i] != '\n')
	{
		i++;
		str_len++;
	}
	i = i - str_len;
	return (str_len);
}

char	get_wrong_item(char *text, int i, int package_len)
{
	int i_compartment2;
	int initial_i;
	
	initial_i = i;
	i_compartment2 = (i + (package_len / 2));
	printf("This package's i2 is: %c\n", text[i_compartment2]);
	while (text[i] != '\n')
	{
		while (text[i_compartment2] != '\n')
		{
			if (text[i] == text[i_compartment2])
				return (text[i]);		
			i_compartment2++;
		}
		i++;
		i_compartment2 = (i + (package_len / 2));
	}
	while (text[i] != '\n')
	{
		while (text[i_compartment2] != '\n')
		{
			printf("Is %c equal to %c ? \n", (text[i_compartment2]), (text[i]));
			if (text[i] == text[i_compartment2])
				return (text[i]);		
			printf("no, apparently.\n");
			i_compartment2++;
		}
		i++;
		i_compartment2 = (i + (package_len / 2));
	}
	return (0);
}


int	get_item_priority(char wrong_item)
{
	if (wrong_item >= 'a' && wrong_item <= 'z')
	{
		printf("wrong item = %c\n", wrong_item);
		printf("value for wrong item = %i\n", ((int)wrong_item - 96));
		return (((int)wrong_item) - 96);
	}
	if (wrong_item >= 'A' && wrong_item <= 'Z')
	{
		printf("wrong item = %c\n", wrong_item);
		printf("value for wrong item = %i\n", ((int)wrong_item - 38));
		return (((int)wrong_item) - 38);
	}
	printf("wrong item = %i\n", (int)wrong_item);
	return (0);
}

int main(void)
{
	int		answer;
	FILE	*problem_3_check;
	char	*text;
	long	numbytes;
	
	problem_3_check = fopen("problem_3_check.txt", "r");
	if(problem_3_check == NULL)
		return (0);
		
	fseek(problem_3_check, 0L, SEEK_END);
	numbytes = ftell(problem_3_check);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_3_check, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_3_check);
	fclose(problem_3_check);
	
	answer = get_sum_of_rearrangement_priorities(text);
	printf("The total Sum of Arrangement Priorities is: %i\n", answer); 
	return(0);
}