/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_strmapi.c									   :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:38:13 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:48:22 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

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
		newstring[i] = (*f)(i, ((char)s + i));
		i++;
	}
	return (newstring);
}
