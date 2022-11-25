/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:55:05 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/24 11:47:55 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* int isdigit(int c);
DESCRIPTION
     The isdigit() function tests for a decimal digit character.  Regardless
     of locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''

     The isnumber() function behaves similarly to isdigit(), but may recognize
     additional characters, depending on the current locale setting.

     The value of the argument must be representable as an unsigned char or
     the value of EOF.

RETURN VALUES
     The isdigit() and isnumber() functions return zero if the character tests
     false and return non-zero if the character tests true. */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/* 
1: i checked if the char has an ascii number in the range of digits. 

2: if it does, i am returning a 1 for true.

3: If not, I am returning 0 for false.

4: kthx.
*/