/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_striteri.c									  :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:37:43 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:38:02 by lhop		  ########   odam.nl		 */
/*																			*/
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
#include "libft.h"

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
