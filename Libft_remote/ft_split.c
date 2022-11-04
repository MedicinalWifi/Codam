/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_split.c										 :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:35:21 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:48:08 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	*resultarray[2];
	int		i;
	int		s_len;
	int		split;

	i = 0;
	s_len = ft_strlen ((char *)s);
	while (i < s_len + 1)
	{
		if (s[i] == c)
			split = i;
		i++;
	}
	resultarray[0] = malloc((split + 1) * sizeof(char));
	resultarray[1] = malloc(((s_len - split) + 1) * sizeof(char));
	if (resultarray[0] == NULL || resultarray [1] == NULL)
		return (NULL);
	i = 0;
	while (split < (s_len - split))
	{
		((char *)resultarray[0])[i] = ((char *)s)[i];
		((char *)resultarray[1])[i] = ((char *)s)[split];
		i++;
		split++;
	}
	return ((char **)resultarray[2]);
}
