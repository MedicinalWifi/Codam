/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 11:00:33 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 	Function name ft_strtrim
	Prototype 			char *ft_strtrim(char const *s1, char const *set);
	Turn in files 		-
	Parameters 			s1: The string to be trimmed.
						set: The reference set of characters to trim.
	Return value 		The trimmed string.
						NULL if the allocation fails.
	External functs. 	malloc
	Description 		Allocates (with malloc(3)) and returns a copy of
						’s1’ with the characters specified in ’set’ removed
						from the beginning and the end of the string. */
#include "ft_printf.h"

static	int	ft_checkset1(char *s1, char *set, int setlen, int strlen)
{
	int		i;
	int		si;

	si = 0;
	i = 0;
	while (si < setlen && i < strlen)
	{
		if (set[si] == s1[i])
		{
			i++;
			si = -1;
		}
		si++;
	}
	return (i);
}

static int	ft_checkset2(char *s1, char *set, int setlen, int strlen)
{
	int		i;
	int		si;
	int		check;

	si = 0;
	i = strlen - 1;
	check = 0;
	while (si < setlen && i >= 0)
	{
		if (set[si] == s1[i])
		{
			i--;
			check++;
			si = -1;
		}
		si++;
	}
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		setlen;
	int		st;
	int		end;
	char	*newstring;
	int		i;

	i = 0;
	setlen = ft_strlen(set);
	st = ft_checkset1((char *)s1, (char *)set, setlen, (int)ft_strlen(s1));
	end = ft_checkset2((char *)s1, (char *)set, setlen, ft_strlen(s1));
	if (st == (int)ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	newstring = malloc((((int)ft_strlen(s1) + 1) - (st + end)) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i <= (((int)ft_strlen(s1) - 1) - (st + end)))
	{
		newstring[i] = (char)s1[i + st];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

/*
1: I create a placeholder for the length of the characterset to be trimmed, 
the start of the new string (st), and the end of the new string (end). I 
also create a loop iterator 'i'. 

2: I use strlen to check the set length. 

3: i use checkset1 to check the start of the string. 

	3a: i create 2 loop iterators, 'i' and 'si', one for string, one 
	for the set. 

	3b: I start a while loop to the condition of si being less than 
	the set strlen, and i being less than the string strlen. 

	3c: if the set[si] equals s1[i], I increase the string iterator, and  
	set si to -1 so it will go to 0 when the loop ends. if the set[si]
	does not equal s1[i], I iterate to the next instance of set to 
	repeat the process until either no set chars were found, 
	or the string has ended. 

	3d: I return the index to indicate the start of the trimmed substring.

4: I then redefine 'end' by using checkset 2, to mark the end of the string.

	4a: This functions the same as checkset 1, except this one is backwards.
	I start at the end of s1 by setting index to strlen of s1, -1 for
	terminating character. I created an index 'check' to see now many chars
	where trimmed off the end. I return 'check'.

5: I create an if statement to the condition of start being the same as 
length of s1. In that case, I return calloc with a parameter of 1, to the 
size of char, for the '\0' byte I need to signify the empty string I will 
return.

6: I then allocate memory to newstring, stringlength of s1 plus 1 for 
null terminator, minus the value of start and end, because those will
be trimmed. Bytes the size of chars. I then protect the memory. 

7: I open a while loop, to the condition of i being less than 
(stringlength of s1 - 1), minus the start plus the end. 

I start copying the trimmed string into the placeholder, by 
using 'i + start' as the iterator. 

8: I then terminate the newstring, and return the result. 

9: kthx. 
	
*/