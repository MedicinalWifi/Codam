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

/* Function name ft_strjoin
Prototype 				char *ft_strjoin(char const *s1, char const *s2);
Turn in files 			-
Parameters 				s1: The prefix string.
						s2: The suffix string.
Return value			The new string.
						NULL if the allocation fails.
External functs. 		malloc
Description 			Allocates (with malloc(3)) and returns a new
						string, which is the result of the concatenation
						of ’s1’ and ’s2’. */
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
