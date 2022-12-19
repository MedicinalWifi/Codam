/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   findmessagestartsignal.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 12:03:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/19 14:55:29 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	findpacketstartsignal(char *text)
{
	char	*place;
	int		i;
	int		check_previous;

	place = (char *)calloc(15, sizeof(char));
	strcpy(place, "0000000000000");
	i = 14;
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
	place[4] = text[4];
	if (place[4] != place[3] && place[4] != place[2] && place[4] != place[1] && place[4] != place[0])
		check_previous++;
	place[5] = text[5];
	if (place[5] != place[4] && place[5] != place[3] && place[5] != place[2] && place[5] != place[1] && place[5] != place[0])
		check_previous++;
	place[6] = text[6];
	if (place[6] != place[5] && place[6] != place[4] && place[6] != place[3] && place[6] != place[2] && place[6] != place[1] && place[6] != place[0])
		check_previous++;
	place[7] = text[7];
	if (place[7] != place[6] && place[7] != place[5] && place[7] != place[4] && place[7] != place[3] && place[7] != place[2] && place[7] != place[1] && place[7] != place[0])
		check_previous++;
	place[8] = text[8];
	if (place[8] != place[7] && place[8] != place[6] && place[8] != place[5] && place[8] != place[4] && place[8] != place[3] && place[8] != place[2] && place[8] != place[1] && place[8] != place[0])
		check_previous++;
	place[9] = text[9];
	if (place[9] != place[8] && place[9] != place[7] && place[9] != place[6] && place[9] != place[5] && place[9] != place[4] && place[9] != place[3] && place[9] != place[2] && place[9] != place[1] && place[9] != place[0])
		check_previous++;
	place[10] = text[10];
	if (place[10] != place[9] && place[10] != place[8] && place[10] != place[7] && place[10] != place[6] && place[10] != place[5] && place[10] != place[4] && place[10] != place[3] && place[10] != place[2] && place[10] != place[1] && place[10] != place[0])
		check_previous++;
	place[11] = text[11];
	if (place[11] != place[10] && place[11] != place[9] && place[11] != place[8] && place[11] != place[7] && place[11] != place[6] && place[11] != place[5] && place[11] != place[4] && place[11] != place[3] && place[11] != place[2] && place[11] != place[1] && place[11] != place[0])
		check_previous++;
	place[12] = text[12];
	if (place[12] != place[11] && place[12] != place[10] && place[12] != place[9] && place[12] != place[8] && place[12] != place[7] && place[12] != place[6] && place[12] != place[5] && place[12] != place[4] && place[12] != place[3] && place[12] != place[2] && place[12] != place[1] && place[12] != place[0])
		check_previous++;
	place[13] = text[13];
	if (place[13] != place[12] && place[13] != place[11] && place[13] != place[10] && place[13] != place[9] && place[13] != place[8] && place[13] != place[7] && place[13] != place[6] && place[13] != place[5] && place[13] != place[4] && place[13] != place[3] && place[13] != place[2] && place[13] != place[1] && place[13] != place[0])
		check_previous++;
	if (check_previous == 13)
		return(14);
	printf("The initial string is: %s.\n", place);	
	i = 14;
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
		place[3] = place[4];
		if (place[3] != place[2] && place[3] != place[1] && place[3] != place[0])
			check_previous++;
		place[4] = place[5];
		if (place[4] != place[3] && place[4] != place[2] && place[4] != place[1] && place[4] != place[0])
			check_previous++;
		place[5] = place[6];
		if (place[5] != place[4] && place[5] != place[3] && place[5] != place[2] && place[5] != place[1] && place[5] != place[0])
			check_previous++;
		place[6] = place[7];
		if (place[6] != place[5] && place[6] != place[4] && place[6] != place[3] && place[6] != place[2] && place[6] != place[1] && place[6] != place[0])
			check_previous++;
		place[7] = place[8];
		if (place[7] != place[6] && place[7] != place[5] && place[7] != place[4] && place[7] != place[3] && place[7] != place[2] && place[7] != place[1] && place[7] != place[0])
			check_previous++;
		place[8] = place[9];
		if (place[8] != place[7] && place[8] != place[6] && place[8] != place[5] && place[8] != place[4] && place[8] != place[3] && place[8] != place[2] && place[8] != place[1] && place[8] != place[0])
			check_previous++;
		place[9] = place[10];
		if (place[9] != place[8] && place[9] != place[7] && place[9] != place[6] && place[9] != place[5] && place[9] != place[4] && place[9] != place[3] && place[9] != place[2] && place[9] != place[1] && place[9] != place[0])
			check_previous++;
		place[10] = place[11];
		if (place[10] != place[9] && place[10] != place[8] && place[10] != place[7] && place[10] != place[6] && place[10] != place[5] && place[10] != place[4] && place[10] != place[3] && place[10] != place[2] && place[10] != place[1] && place[10] != place[0])
			check_previous++;
		place[11] = place[12];
		if (place[11] != place[10] && place[11] != place[9] && place[11] != place[8] && place[11] != place[7] && place[11] != place[6] && place[11] != place[5] && place[11] != place[4] && place[11] != place[3] && place[11] != place[2] && place[11] != place[1] && place[11] != place[0])
			check_previous++;
		place[12] = place[13];
		if (place[12] != place[11] && place[12] != place[10] && place[12] != place[9] && place[12] != place[8] && place[12] != place[7] && place[12] != place[6] && place[12] != place[5] && place[12] != place[4] && place[12] != place[3] && place[12] != place[2] && place[12] != place[1] && place[12] != place[0])
			check_previous++;
		place[13] = text[i];
		if (place[13] != place[12] && place[13] != place[11] && place[13] != place[10] && place[13] != place[9] && place[13] != place[8] && place[13] != place[7] && place[13] != place[6] && place[13] != place[5] && place[13] != place[4] && place[13] != place[3] && place[13] != place[2] && place[13] != place[1] && place[13] != place[0])
			check_previous++;
		i++;
		if (check_previous == 13)
			return(i);
	}
	return (0);
}

int main(void)
{
	int		answer;
	FILE	*problem_6_input;
	char	*text;
	long	numbytes;
	
	problem_6_input = fopen("problem_6_input.txt", "r");
	if(problem_6_input == NULL)
		return (0);
		
	fseek(problem_6_input, 0L, SEEK_END);
	numbytes = ftell(problem_6_input);
	printf("The Content of This File is %li Bytes.\n\n", numbytes);
	fseek(problem_6_input, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
		
	fread(text, sizeof(char), numbytes, problem_6_input);
	fclose(problem_6_input);
	
	answer = findpacketstartsignal(text);
	printf("The packet starts at: %i\n", answer); 
	return(0);
}