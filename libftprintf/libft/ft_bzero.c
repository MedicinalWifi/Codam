/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:43:38 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:29:17 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* void bzero(void *s, size_t n);

DESCRIPTION
     The bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing. */
#include "libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

/* 
1: I create a while loop iterator, and set it to 0.

2: I set my while loop to the condition of i being lower than size_t n, which
is the amount of bytes we want to be writing in the 'void *s' string.

3: inside my whileloop, I am writing to the memory adress of void *s, plus
the value of i. What I write, is the terminator character '\0'. 

4: no return value necessary, all this function does is write in specified
memory, filling it with a specified amount of '\0'. 

5: kthx.
 */
