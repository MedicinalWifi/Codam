/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_tolower.c									   :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/11 11:43:06 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/24 13:12:52 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

/* DESCRIPTION
     The tolower() function converts an upper-case letter to the corresponding
     lower-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.

     Although the tolower() function uses the current locale, the tolower_l()
     function may be passed a locale directly. See xlocale(3) for more infor-
     mation.

RETURN VALUES
     If the argument is an upper-case letter, the tolower() function returns
     the corresponding lower-case letter if there is one; otherwise, the argu-
     ment is returned unchanged. */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*

1: i checked if the char's ascii number is 
in the range of uppercase alpha chars. 

2: if it is, i am converting it to lower 
range by adding 32, which moves it 32 places up.

3: if it is not an upper case char, 
i do nothing and return the char unchanged.

4: kthx.
*/
