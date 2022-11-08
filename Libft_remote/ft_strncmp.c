/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:18:57 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/07 16:05:24 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i + 1 < len)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* 
strncmp: we're trying to compare the values of two strings, 
but only for a set amount of characters.

1: I create an index to move through the strings.

2: I create an int to store comparison results.

3: I open a while loop on the condition of s1 not being \0, 
s2 not being \0, and the index being lower than the len, 
which is the number of chars we are supposed to search.

4: I redefine cmp to be its current value, and i add 
string 1[i] minus string 2 [i]. That will start making the 
value drop or increase every loop, based on the sum. 


5: I create my first 'if'.
So, when that cmp placeholder is positive, that means s1 was bigger. 
That means I should return 1: s1 is bigger. 

6: Second if, saying the cmp value is 0. that means s1 and s2 were equal.
I should return 0.

7: Third if, saying the cmp value is <0. That means s2 was bigger.
I should return -1.

8: kthx.
*/