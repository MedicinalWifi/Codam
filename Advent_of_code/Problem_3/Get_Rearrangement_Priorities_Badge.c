/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Get_Rearrangement_Priorities_Badge.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 12:33:24 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/08 12:33:14 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 	get_sum_of_rearrangement_priorities(char *text);
int		get_group_package_lengths(char *text, int i);
char	get_badge(char *text, int i, int package_len1, int package_len2);
int		get_item_priority(char badge);
int		get_item_priority(char badge);

int	get_sum_of_rearrangement_priorities_badge(char *text)
{
	int		item_priority;
	int		priority_sum;
	int		package_len1;
	int		package_len2;
	int		package_len3;
	int		i;
	int		initial_i;
	char	badge;

	item_priority = 0;
	priority_sum = 0;
	package_len1 = 0;
	package_len2 = 0;
	package_len3 = 0;
	i = 0;
	initial_i = 0;
	badge = '0';
	while (text[i] != '\n')
	{
		initial_i = i;
		package_len1 = get_group_package_lengths(text, i);
		i = (i + (package_len1 + 1));
		printf("Package 1's Length is: %i\n", package_len1);
		
		package_len2 = get_group_package_lengths(text, i);
		i = (i + (package_len2 + 1));
		printf("Package 2's Length is: %i\n", package_len2);
		
		package_len3 = get_group_package_lengths(text, i);
		i = (i + (package_len3 + 1));
		printf("Package 3's Length is: %i\n", package_len3);
		
		i = initial_i;
		badge = get_badge(text, i, package_len1, package_len2);

		item_priority = get_item_priority(badge);
		priority_sum += item_priority;
		i = (i + (package_len1 + package_len2 + package_len3) + 3);
		if (text[i + 3])
			printf("i is now set to %c %c %c \n\n", text[i], text[i + 1], text[i + 2]);
		else 
			printf("This was the last package \n\n");
	}
	return (priority_sum);
}

int	get_group_package_lengths(char *text, int i)
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

char	get_badge(char *text, int i, int package_len1, int package_len2)
{
	int		initial_i;
	int 	i_compartment1;
	int 	i_compartment2;
	int 	i_compartment3;
	char	match;
	
	initial_i = i;
	i_compartment1 = i;
/* 	printf("compartment 1 starts at %c \n", text[i_compartment1]); */
	i_compartment2 = (initial_i + (package_len1 + 1));
/* 	printf("compartment 2 starts at %c \n", text[i_compartment2]); */
	i_compartment3 = (initial_i + (package_len1 + package_len2 + 2));
/* 	printf("compartment 3 starts at %c \n", text[i_compartment3]); */
	match = '1';
	
	while (text[i_compartment2] != '\n')
	{
		while (text[i_compartment1] != '\n')
		{
			if (text[i_compartment1] == text[i_compartment2])
			{
				while(text[i_compartment3] != '\n')
				{
					if (text[i_compartment3] == text[i_compartment1])
					{
						printf("compartment 3 is now at %c %c %c \n", text[i_compartment3], text[i_compartment3 + 1], text[i_compartment3 + 2]);
						return (text[i_compartment3]);
					}
					i_compartment3++;
				}
				i_compartment3 = initial_i + package_len1 + package_len2 + 2;
			}
			i_compartment1++;
		}
		i_compartment1 = initial_i;
		i_compartment2++;
	}
	return ('~');
}


int	get_item_priority(char badge)
{
	if (badge >= 'a' && badge <= 'z')
	{
		printf("badge item = %c\n", badge);
		printf("value for badge item = %i\n", ((int)badge - 96));
		return (((int)badge) - 96);
	}
	if (badge >= 'A' && badge <= 'Z')
	{
		printf("badge item = %c\n", badge);
		printf("value for badge item = %i\n", ((int)badge - 38));
		return (((int)badge) - 38);
	}
	printf("badge item = %i\n", (int)badge);
	return (0);
}

int main(void)
{
	int		answer;
	FILE	*problem_3_input;
	char	*text;
	long	numbytes;
	
	problem_3_input = fopen("problem_3_input.txt", "r");
	if(problem_3_input == NULL)
		return (0);
		
	fseek(problem_3_input, 0L, SEEK_END);
	numbytes = ftell(problem_3_input);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_3_input, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_3_input);
	fclose(problem_3_input);
	
	answer = get_sum_of_rearrangement_priorities_badge(text);
	printf("The total Sum of the Badge's Arrangement Priorities is: %i\n", answer); 
	return(0);
}

//Answer 2504 too high