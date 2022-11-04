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
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	i2;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	newstring = malloc(((s1_len + s2_len) + 1) * sizeof(char));
	i = 0;
	i2 = 0;
	if (newstring == NULL)
		return (NULL);
	while (newstring[i] != '\0' && i <= s1_len)
	{
		newstring[i] = s1[i];
		i++;
	}
	while (newstring[i] != '\0' && i2 <= s2_len)
	{
		newstring[i] = s2[i2];
		i++;
		i2++;
	}
	newstring[i] = '\0';
	return (newstring);
}
