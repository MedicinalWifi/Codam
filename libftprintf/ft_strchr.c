/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 12:06:13 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* char *strchr(const char *s, int c);
DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string. */
#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len + 1)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
/* 
1: First I set a loop iterator, called 'i'. I also create a placeholder 
for the stringlength of '*s', for which i use strlen.

2: I open a whileloop, to the condition of 'i' being less than the length
of the string 's' plus 1, to include the '\0'. This so it can keep
iterating to the very end of the string.

3: In that whileloop, I nest an if statement to the condition of 's[i]'
being equal to c. I typecast int c as a char, so that I can compare it
to the char data of 's[i]'. 

4: if that if statement is true, I return a pointer to the location of 
the occurance.

5: If the whileloop ends without having returned a pointer, that means
the search has finished without finding c. I return NULL.

6: kthx.
*/