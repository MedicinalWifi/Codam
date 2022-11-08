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
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (s_len <= len)
		substring = malloc((s_len + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len && i < s_len && start < s_len)
	{
		*(substring + i) = *(s + start);
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
