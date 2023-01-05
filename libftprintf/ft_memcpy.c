/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:41 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:29:51 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* void *memcpy(void *restrict dst, const void *restrict src, size_t n);
	 DESCRIPTION
     The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst. */
#include "libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst != NULL || src != NULL)
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/* 
1: I create a loop iterator called 'i'. 

2: i create an if statement to check for the condition that 'dst' contains
something, and 'src' contains something. if that's not true, then there's
either nothing to copy, nothing to copy to, or both. So i return dst.

3: if those variables are not empty, I start my while loop.
While i is lower than 'n', which is the amount of bytes we want to copy, 
the current element of the 'dst' will then contain the current element 
of 'src'. I typecast dst and src as char pointers, because they were void
pointers, which you cannot write data onto. 

4: I return the overwritten dst.

5: kthx.
*/