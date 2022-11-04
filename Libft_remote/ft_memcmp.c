/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:38 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/31 13:46:03 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	cmp;

	i = 0;
	cmp = 0;
	while ((char *)(s1 + i) != '\0' && (char *)(s2 + i) != '\0' && i < n)
	{
		cmp += (char *)(s1 + i) - (char *)(s2 + i);
		i++;
	}
	if (cmp == '0')
		return (0);
	else
	{
		while ((char *)(s1 + i) != '\0' && (char *)(s2 + i) != '\0' && i < n)
		{
			cmp += (char *)(s1 + i) - (char *)(s2 + i);
			if (cmp != '0')
			{
				return (cmp);
			}
			i++;
		}
	}
	return (0);
}
