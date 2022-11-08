/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_strjoin.c									   :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:36:14 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:48:16 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	i2;

	newstring = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	i = 0;
	i2 = 0;
	if (newstring == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		newstring[i] = s1[i];
		i++;
	}
	while (i2 < ft_strlen(s2))
	{
		newstring[i] = s2[i2];
		i++;
		i2++;
	}
	newstring[i] = '\0';
	return (newstring);
}
