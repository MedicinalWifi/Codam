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

int		ft_checkset1(char const *s1, char const *set, int set_len, int str_len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_checkset2(char const *s1, char const *set, int set_len, int str_len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		set_len;
	int		st;
	int		end;
	char	*newstring;
	int		i;

	i = 0;
	set_len = ft_strlen(set);
	st = ft_checkset1(s1, set, set_len, (int)ft_strlen(s1));
	end = ft_checkset2(s1, set, set_len, ft_strlen(s1));
	if (st == (int)ft_strlen(s1))
	{
		newstring = ft_calloc(2, sizeof(char));
		return (newstring);
	}
	newstring = malloc((((int)ft_strlen(s1) + 1) - (st + end)) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i <= ((((int)ft_strlen(s1) - 1) - st) - end))
	{
		newstring[i] = (char)s1[i + st];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

int	ft_checkset1(char const *s1, char const *set, int set_len, int str_len)
{
	int		i;
	int		si;

	si = 0;
	i = 0;
	while (si < set_len && i < str_len)
	{
		if (set[si] == s1[i])
		{
			i++;
			si = -1;
		}
		si++;
	}
	return (i);
}

int	ft_checkset2(char const *s1, char const *set, int set_len, int str_len)
{
	int		i;
	int		si;
	int		check;

	si = 0;
	i = str_len - 1;
	check = 0;
	while (si < set_len && i >= 0)
	{
		if (set[si] == s1[i])
		{
			i--;
			check++;
			si = -1;
		}
		si++;
	}
	return (check);
}
