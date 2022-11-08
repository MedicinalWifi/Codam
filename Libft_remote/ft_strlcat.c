/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:34:33 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/07 14:54:40 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	i2;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	i = dst_len;
	i2 = 0;
	while (*(src + i2) != '\0' && i2 < src_len && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i2);
		i++;
		i2++;
	}
	*(dst + i) = '\0';
	return (dst_len + src_len);
}

/*
strlcat: we're returning the stringlength of two combined strings.

1: I created an index for source length.

2: I created an index for destination length.

3: I created a placeholder for the concatenated stringlength.

4: I return the concatenated string length.

5: kthx.
*/