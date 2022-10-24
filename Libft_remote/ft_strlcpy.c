/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:56:13 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 13:33:56 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	strl;
	size_t	i;

	strl = ft_strlen (src) + 1;
	i = 0;
	dstsize -= 1;
	while (i <= dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strl);
}

/* STRLCPY

1: I set a placeholder for the actual length of the src. I add 1 for null.

2: I set an index to move through the strings. 

3: I set dstsize to -= 1, because strcpy only is allowed to cpy that many char.

4: I open a while loop on the condition that the index is less than dstsize -1.
I do this to leave 1 empty spot for the NULL terminating character.

5: I overwrite dst[i], the first spot in the destination array, with src[i],
the first spot in the source array.

6: I set the index to move on 1 place after the overwrite is complete. 

7: When the loop has written src content into the dst, into all but 1 spots,
(dstsize-1), I then write the null terminating character. "\0"

8: This program then returns the destination, with the source copied into it.

9: kthx.
*/ 