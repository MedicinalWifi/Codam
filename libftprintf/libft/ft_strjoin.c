/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:36:14 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:30:36 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_strjoin
Prototype 				char *ft_strjoin(char const *s1, char const *s2);
Turn in files 			-
Parameters 				s1: The prefix string.
						s2: The suffix string.
Return value			The new string.
						NULL if the allocation fails.
External functs. 		malloc
Description 			Allocates (with malloc(3)) and returns a new
						string, which is the result of the concatenation
						of ’s1’ and ’s2’. */
#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	i2;

	newstring = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	i = 0;
	i2 = 0;
	if (newstring == NULL)
		return (NULL);
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		newstring[i] = s2[i2];
		i++;
		i2++;
	}
	newstring[i] = '\0';
	return (newstring);
}
/*
1: I create a placeholder for the string, 2 loop iterators called 'i' and 
'i2'. 

2: I allocate memory to newstring, by giving it enough space of the 
stringlength of s1 and s2 combined, adding 1 space for '\0'. 
I protect this allocation.

3: I first copy s1 into the placeholder newstring, I use the first 
loop iterator for this. 

4: I then copy the second string into newstring, by using the 
first loop iterator to keep my spot inside s1, and the 2nd 
to start from 0 in s2. 

5: I then place a '\0' at the end of the string and return the 
result. 

6: kthx.
*/
