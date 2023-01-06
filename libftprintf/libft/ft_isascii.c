/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:01:47 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/24 11:51:06 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* int isascii(int c);

DESCRIPTION
     The isascii() function tests for an ASCII character, which is any charac-
     ter between 0 and octal 0177 inclusive. */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*

1: i checked if the char has a ascii number inbetween 0 and 127, 
which includes all listed chars in the ascii table.
I do this by using the 'is equal or higher than' operator, '>=', 
and the 'is lower than or equal to' operator, '<='.
To apply both, i use the 'and' operator, which is '&&'. 

2: if the number is between 0 and 127, I return 1 for true.

3: if it does not, I return 0 for false.

4: kthx.
*/