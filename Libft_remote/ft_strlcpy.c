/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:56:13 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/20 13:12:27 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t strlcpy(char *dst, char *src, size_t dstsize)
{
    int i;
    i = 0;
    while(i <= dstsize-1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = "\0";
    return((char*)dst);
}

/* STRLCPY, we're copying the source string into the destination string, 
copying a max of dstsize characters from the source so that the src
doesn't overflow the dst. 

1: I set an index to move through the strings. 

2: I open a while loop on the condition that the index is less than dstsize -1.
I do this to leave 1 empty spot for the NULL terminating character.

3: I overwrite dst[i], the first spot in the destination array, with src[i],
the first spot in the source array.

4: I set the index to move on 1 place after the overwrite is complete. 

5: When the loop has written src content into the dst, into all but 1 spots,
(dstsize-1), I then write the null terminating character. "\0"

6: This program then returns the destination, with the source copied into it.

7: kthx.
*/ 