/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:37:43 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_striteri
Prototype 			void ft_striteri(char *s, void (*f)(unsigned int, char*));
Turn in files 		-
Parameters 			s: The string on which to iterate.
					f: The function to apply to each character.
Return value 		None
External functs. 	None
Description 		Applies the function ’f’ on each character of
					the string passed as argument, passing its index
					as first argument. Each character is passed by
					address to ’f’ to be modified if necessary. */
#include "ft_printf.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
	{	
		(*f)(i, (s + i));
		i++;
	}
}

/*
1: I first create a loop iterator called 'i' and a placeholder for 
the length of the string *s. I set these to 0, and to the 
strlen of *s by using the strlen function.

2: I then create a whileloop to the condition of 'i' being less than 
the string length.  

3: In this while loop, I apply the function passed in the parameter, 
and give it the arguments 'i', and the location of the character. 

4: kthx.
*/
