/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Get_3_Biggest_Stash.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 11:43:10 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/05 11:29:49 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_food_count(char *input, int i);
int get_calorie_strlen(char *input, int i);
int calculate_package_calories(char *input, int package_food_count, int i);
int get_food_count(char *input, int i);
char	*ft_substr(char const *s, int start, int len);

int get_biggest_package(char *input)
{
	int	i;
	int package_food_count;
	int package_calories;
	int biggest_package;
	int second_biggest;
	int third_biggest;

	i = 0;
	package_food_count = 0;
	package_calories = 0;
	biggest_package = 0;
	second_biggest = 0;
	third_biggest = 0;
	printf("Initiated function.\n");
	while (input[i] != '\0')
	{
		while (!(input[i] == '\n' && input[i + 1] == '\n') && input[i] != '\0')
		{
			printf("Counting Through Packages. Current Package: %i\n", i);
			package_food_count = get_food_count(input, i);
			package_calories = calculate_package_calories(input, package_food_count, i);
			while (!(input[i] == '\n' && input[i + 1] == '\n') && input[i] != '\0')
				i++;
		}
		if (package_calories > biggest_package)
		{
			third_biggest = second_biggest;
			second_biggest = biggest_package;
			biggest_package = package_calories;
		}
		else if (package_calories > second_biggest)
		{
			third_biggest = second_biggest;
			second_biggest = package_calories;
		}
		else if (package_calories > third_biggest)
			third_biggest = package_calories;
		printf("Biggest Package yet: %i\n", biggest_package);
		while (input[i] == '\n')
			i++;
	}
	printf("\n\nThird Biggest Package: %i\n", third_biggest);
	printf("Second Biggest Package: %i\n", second_biggest);
	printf("Biggest Package: %i\n", biggest_package);
	printf("Sum of top 3: %i\n", (third_biggest + second_biggest + biggest_package));
	return (biggest_package);
}

int get_calorie_strlen(char *input, int i)
{
	int	calorie_strlen;

	calorie_strlen = 0;
	while (input[i] && input[i] != '\n')
	{
		calorie_strlen++;
		i++;
	}
	return (calorie_strlen);
}

int calculate_package_calories(char *input, int package_food_count, int i)
{
	int calorie_string;
	int food_calories;
	int food_i;
	int package_calories;
	
	package_calories = 0;
	calorie_string = 0;
	food_i  = 0;
	
	while (food_i <= package_food_count)
	{
		calorie_string = get_calorie_strlen(input, i);
		food_calories = atoi(ft_substr(input, i, calorie_string));
		package_calories += food_calories;
		food_i++;
		i += (calorie_string + 1);
	}
	return (package_calories);
}

int get_food_count(char *input, int i)
{
	int	food_count;
	
	food_count = 0;
	while (input[i] && !(input[i] == '\n' && input[i + 1] == '\n'))
	{
		if (input[i] && input[i] != '\n')
		{
			food_count++;
			while (input[i] != '\n' && input[i] != '\0')
				i++;
		}
		if (input[i] == '\n' && input[i + 1] != '\n')
			i++;
	}
	return (food_count);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*substring;
	int		i;
	int		s_len;

	s_len = strlen(s);
	i = 0;
	if (start >= s_len || !s || len == 0)
		return (calloc(1, sizeof(char)));
	if ((s_len - start) <= len)
		substring = malloc(((s_len - start) + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len && i < s_len && start < s_len)
	{
		*(substring + i) = *(s + start);
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

int main(void)
{
	int		answer;
	FILE	*problem_1_input;
	char	*text;
	long	numbytes;
	
	problem_1_input = fopen("problem_1_input.txt", "r");
	if(problem_1_input == NULL)
		return (0);
	fseek(problem_1_input, 0L, SEEK_END);
	numbytes = ftell(problem_1_input);
	printf("The Content of This File is %li Bytes.\n", numbytes);
	fseek(problem_1_input, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
	fread(text, sizeof(char), numbytes, problem_1_input);
	fclose(problem_1_input);

	answer = get_biggest_package(text);
	printf("\n\n kthx"); 
	return(0);
}

/* 
1: Change package's lines to ints 
2: Add the ints.
3: Save the int in placeholder
4: Get the next 'package'
5: Change package's lines to ints
6: Add the ints.
7: If it is bigger, save the int in placeholder.
8: Repeat until end is reached.
*/