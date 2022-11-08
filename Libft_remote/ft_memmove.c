/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:43 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/07 15:17:37 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	if (!dst || !src)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *)(dst + (len - 1))) = *((char *)(s + (len - 1)));
			len--;
		}
		return ((void *)dst);
	}
	while (dst < src && i < len)
	{
		*((char *)(dst + i)) = *((char *)(s + i));
		i++;
	}
	return ((void *)dst);
}
