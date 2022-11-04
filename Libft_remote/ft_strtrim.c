/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_strtrim.c									   :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:35:52 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:48:30 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	char	*ptr;
	char	*newstring;
	size_t	i;

	i = 0;
	set_len = ft_strlen((char *)set);
	ptr = ft_strnstr(s1, set, set_len);
	newstring = malloc((set_len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i <= set_len)
	{
		newstring[i] = *ptr;
		ptr++;
		i++;
	}
	return (newstring);
}
