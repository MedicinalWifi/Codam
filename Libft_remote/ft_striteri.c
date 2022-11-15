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
