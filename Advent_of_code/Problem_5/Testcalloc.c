/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Testcalloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/15 10:52:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/12/15 11:29:34 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char** test;
	int i;
	
	i = 0;
	test = (char **)calloc(3, sizeof(char *));
	while (i <= 2)
	{
		test[i] = (char *)calloc(5, sizeof(char));
		i++;
	}
	strcpy(test[0], "hey");
	strcpy(test[1], "111");
	strcpy(test[2], "222");
	
	test[0][0] = '1';
	
	printf("%s", test[0]);
	return(0);
}