/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:18:57 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/25 13:30:41 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
     The strcmp() and strncmp() functions lexicographically compare the null-
     terminated strings s1 and s2.

     The strncmp() function compares not more than n characters.  Because
     strncmp() is designed for comparing strings rather than binary data,
     characters that appear after a `\0' character are not compared.

   RETURN VALUES
     The strcmp() and strncmp() functions return an integer greater than,
     equal to, or less than 0, according as the string s1 is greater than,
     equal to, or less than the string s2.  The comparison is done using
     unsigned characters, so that `\200' is greater than `\0'. */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
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
1: I first set up a loop iterator and set it to 0.

2: Then I create an if statement to the condition of n being equal
to 0. If it is, then there are 0 characters to compare, and I 
return 0 for equal. 

3: I then open a while loop to the condition of s1 and s2 not 
having terminated, and i being less than the number of chars
to be compared, -1 because it is a size_t value. size_t 
starts at 1, our int starts at 0. 

4: I make 2 if statements, one for s1 being smaller, returning -1,
another for s1 being bigger, returning 1. 
The strings are typecasted as unsigned chars, because this is the 
only way it will work with non-ascii characters too. 
Unsigned chars will extend range from -128 - 127, to 0 - 255. 
That allows for inclusion of non ascii chars. 

5: if these two statements fail, or the entire whileloop fails, 
I handle the '0' option in the final return, in which case I 
return the difference when subtracting s2 from s1 at the 
iteration of 'i'.

6: kthx.
*/