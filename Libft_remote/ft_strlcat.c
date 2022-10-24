/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:34:33 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 14:10:37 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(const char *src, char *dst, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	strlcat;
	size_t	i;

	src_len = ft_strlen ((char *)src);
	dst_len = ft_strlen ((char *)dst);
	strlcat = src_len + dst_len + 1;
	i = 0;
	while (dst[i] != '\0' && i <= dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlcat);
}

/*
strlcat: we're returning the stringlength of two combined strings.

1: I created an index for source length.

2: I created an index for destination length.

3: I created a placeholder for the concatenated stringlength.

4: I return the concatenated string length.

5: kthx.
*/