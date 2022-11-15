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
	int		i;
	int		string_i;
	int		string_len;
	char	**answer;
	int		strlen;
	char	*string;
	char	*set;

	set = &c;
	i = 0;
	string_i = 0;
	s = ft_strtrim(s, set);//trimming the deliminating characters off the front and end.
	string_len = ft_strlen(s);//checking the length of the string.
	while (s[i] != '\0')
	{
		while (s[i] != c)
		{
			string_len++;
			i++;
		}
		answer[string_i] = malloc((string_len + 1 )* sizeof(char));
		answer[string_i] = ft_stringwrite((i - string_len), string_len, s, answer, string_i);
		string_i++;
	}
}

char	*ft_stringwrite(int i, int string_len, char	*s, char *answer, int string_i)
{
	int	ii;

	ii = 0
	while (i <= string_len)
	{
		answer[string_i][ii] = s[i];
		i++;
		ii++;
	}
	answer[string_i][ii] = '\0';
	return (answer);
}