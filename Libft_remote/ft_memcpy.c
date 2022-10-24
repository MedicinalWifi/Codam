/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:41 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 14:38:47 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

/* 
memcpy: we're trying to copy from one memory place to another.

1: I create an index.

2: I create a while loop: it exits after length n.

3: I write the dest into the src. 

4: I return the overwritten dst.

5: kthx.
*/