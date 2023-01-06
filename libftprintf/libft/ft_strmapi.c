/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 11:18:08 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:31:00 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_strmapi
Prototype		char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
Turn in files 	-
Parameters 		s: The string on which to iterate.
				f: The function to apply to each character.
Return value 	The string created from the successive applications
				of ’f’.
				Returns NULL if the allocation fails.
External 
functs. 		malloc
Description 	Applies the function ’f’ to each character of the
				string ’s’, and passing its index as first argument
				to create a new string (with malloc(3)) resulting
				from successive applications of ’f’. */
#include "libftprintf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		str_len;
	char	*newstring;

	i = 0;
	str_len = ft_strlen(s);
	newstring = malloc((str_len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i < str_len)
	{	
		newstring[i] = (*f)(i, (char)s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

/*
1: I first create a loop iterator called 'i', a placeholder for 
stringlength, and a placeholder for the new string. 

2: I allocate memory to newstring by using stringlength + 1
for the terminating null character. I protect the allocation.

3: I create a while loop to iterate through the string, 
I copy the altered iterations into newstring. 

4: I terminate newstring, and return the result. 

5: kthx. 
*/
