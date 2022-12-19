/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   findpacketstartsignal.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 12:03:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/16 13:02:08 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	findpacketstartsignal(char *text)
{
	char	place[4];
	int		i;
	int		check_previous;

	i = 4;
	check_previous = 0;
	place[0] = text[0];
	place[1] = text[1];
	if (place[1] != place[0])
		check_previous++;
	place[2] = text[2];
	if (place[2] != place[1] && place[2] != place[0])
		check_previous++;
	place[3] = text[3];
	if (place[3] != place[2] && place[3] != place[1] && place[3] != place[0])
		check_previous++;
	if (check_previous == 3)
		return(4);
	while (text[i] != '\n')
	{
		check_previous = 0;
		place[0] = place[1];
		place[1] = place[2];
		if (place[1] != place[0])
			check_previous++;
		place[2] = place[3];
		if (place[2] != place[1] && place[2] != place[0])
			check_previous++;
		place[3] = text[i];
		if (place[3] != place[2] && place[3] != place[1] && place[3] != place[0])
			check_previous++;
		i++;
		if (check_previous == 3)
			return(i);
	}
	return (0);
}

int main(void)
{
	int		answer;
	FILE	*problem_6_check;
	char	*text;
	long	numbytes;
	
	problem_6_check = fopen("problem_6_check.txt", "r");
	if(problem_6_check == NULL)
		return (0);
		
	fseek(problem_6_check, 0L, SEEK_END);
	numbytes = ftell(problem_6_check);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_6_check, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_6_check);
	fclose(problem_6_check);
	
	answer = findpacketstartsignal(text);
	printf("The result string is: %i\n", answer); 
	return(0);
}