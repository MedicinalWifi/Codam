/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Calculate_Strategy_Guide_Outcome.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:31:35 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/05 12:25:28 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
ROCK:
A / X / 1
BEAT: ROCK(A) 6 + 1 >> SCISSORS(Z) (0 + 3)
DRAW: ROCK(A) 3 + 1 >> ROCK(X) (3 + 1)
LOSS: ROCK(A) 0 + 1 >> PAPER(Y) (6 + 2)

PAPER:
B / Y / 2
BEAT: PAPER(B) 6 + 2 >> ROCK(X) (0 + 1)
DRAW: PAPER(B) 3 + 2 >> PAPER(Y) (3 + 2)
LOSS: PAPER(B) 0 + 2 >> SCISSORS(Z) (6 + 3)

SCISSORS:
C / Z / 3
BEAT: SCISSORS(C) 6 + 3 >> PAPER(Y) (0 + 2)
DRAW: SCISSORS(C) 3 + 3 >> SCISSORS(Z) (3 + 3)
LOSS: SCISSORS(C) 0 + 3 >> ROCK (X) (6 + 1)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	get_game_score(char *text, int i);
int get_my_total_score(char *text);

int get_my_total_score(char *text)
{
	int i;
	int	game_score;
	int total_game_score;

	i = 0;
	game_score = 0;
	total_game_score = 0;
	while (text[i])
	{
		game_score = get_game_score(text, i);
		i += 4;
		total_game_score += game_score;
	}
	return (total_game_score);	
}

int	get_game_score(char *text, int i)
{
	if (text[i] == 'A' && text[i + 2] == 'X')
		return (0 + 3);
	if (text[i] == 'A' && text[i + 2] == 'Y')
		return (3 + 1);
	if (text[i] == 'A' && text[i + 2] == 'Z')
		return (6 + 2);
		
	if (text[i] == 'B' && text[i + 2] == 'X')
		return (0 + 1);
	if (text[i] == 'B' && text[i + 2] == 'Y')
		return (3 + 2);
	if (text[i] == 'B' && text[i + 2] == 'Z')
		return (6 + 3);
	
	if (text[i] == 'C' && text[i + 2] == 'X')
		return (0 + 2);
	if (text[i] == 'C' && text[i + 2] == 'Y')
		return (3 + 3);
	if (text[i] == 'C' && text[i + 2] == 'Z')
		return (6 + 1);	
	return (0);
}

int main(void)
{
	int		answer;
	FILE	*problem_2_input;
	char	*text;
	long	numbytes;
	
	problem_2_input = fopen("problem_2_input.txt", "r");
	if(problem_2_input == NULL)
		return (0);
	fseek(problem_2_input, 0L, SEEK_END);
	numbytes = ftell(problem_2_input);
	printf("The Content of This File is %li Bytes.\n", numbytes);
	fseek(problem_2_input, 0L, SEEK_SET);
	
	text = (char *)calloc(numbytes + 1, sizeof(char));
	if (text == NULL)
		return (0);
	fread(text, sizeof(char), numbytes, problem_2_input);
	fclose(problem_2_input);

	answer = get_my_total_score(text);
	printf("My total score would be: %i\n", answer); 
	return(0);
}