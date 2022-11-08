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
int		ft_checkset1(char const *s1, char const *set, size_t set_len, size_t str_len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_checkset2(char const *s1, char const *set, size_t set_len, size_t str_len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	str_len;
	size_t	start_i;
	size_t	end_i;
	char	*newstring;
	int		i;

	i = 0;
	set_len = ft_strlen(set);
	str_len = ft_strlen(s1);
	start_i = ft_checkset1(s1, set, set_len, str_len);
	end_i = ft_checkset2(s1, set, set_len, str_len);
	newstring = malloc(((str_len - start_i) - end_i + 1) * sizeof(char));
	while (i < ((str_len - start_i) - end_i))
	{
		
	}
}

int	ft_checkset1(char const *s1, char const *set, size_t set_len, size_t str_len)
{
	size_t	i;
	size_t si;
	size_t check;

	check = 0;
	si = 0;
	i = 0;
	while (i < str_len)
	{
		while (si < set_len)
		{
			if (s1[i] == set[ii])
			{
				i++;
				check++;
			}
			si++;
		}
		if (check > 0)
			si = 0;
		if (check == 0)
			return (i);
	}
	return (i);
}

int	ft_checkset2(char const *s1, char const *set, size_t set_len, size_t str_len)
{
	size_t	i;
	size_t	si;
	size_t	check;

	check = 0;
	si = 0;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		while (si < set_len)
		{
			if (s1[i] == set[ii])
			{
				i--;
				check++;
			}
			si++;
		}
		if (check > 0)
			si = 0;
		if (check == 0)
			return (i);
	}
	return (check);
}