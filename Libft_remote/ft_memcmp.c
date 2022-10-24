/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:38 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 15:21:00 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 0;
	while ((char *)(s1 + i) != '\0' && (char *)(s2 + i) != '\0' && i <= n)
	{
		cmp += (char *)(s1 + i) - (char *)(s2 + i);
		i++;
	}
	if (cmp > 0)
	{
		return (1);
	}
	else if (cmp == 0)
	{
		return (0);
	}
	else if (cmp < 0)
	{
		return (-1);
	}
	return (-2);
}
