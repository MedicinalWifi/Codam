/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_substr.c										:+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:36:53 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:48:35 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	substring = malloc(len * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring = (char *)(s + start);
		i++;
		start++;
	}
	return (substring);
}
