/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:05:52 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/24 11:55:50 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* int isprint(int c);

DESCRIPTION
     The isprint() function tests for any printing character, including space
     (` ').  The value of the argument must be representable as an unsigned
     char or the value of EOF.

RETURN VALUES
     The isprint() function returns zero if the character tests false and
     returns non-zero if the character tests true. */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/* 
1: i checked if the char has an ascii number in the range of printable 
chars. The ASCII range for this in decimal is between 32 and 126. 

2: if it does, i am returning 1 for true.

3: if not, then I return 0 for false.

4: kthx.
*/