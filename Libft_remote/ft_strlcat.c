/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:34:33 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 15:24:12 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlcat(const char * src, char * dst, size_t dstsize)
{
    int src_len;
    src_len = ft_strlen(*src);
    
    int i;
    i = src_len + dstsize;

    int write_i;
    write_i = 0;

    int src_i;
    src_i = 0;

    char strlcat[i];
    while (write_i <= dstsize && dst[write_i] != "\0")
    {
        strlcat[write_i] = dst[write_i];
        write_i++;
    }
    while (write_i <= i)
    {
        strlcat[write_i] = src[src_i];
        write_i++;
        src_i++;
    }
    strlcat[write_i] = "\0";
    return((char*)strlcat);
}

/*
strlcat: we're trying to combine two strings.

1: I created an index for source length.

2: I created an placeholder for the total length of new string.

3: I created an index for writing into the string.

4: I created an index for looping through the source to be added.

5: I created a new place for the string.

6: I started a while loop on the condition that the writing index is 
lower than the destination size, and the destination hasn't reached "\0"

7: I started another while loop on the condition of the writing index
being lower than the sum of the dst+src. 

8: I add the source to the destination. 

9: I add the final null terminating character.

10: I return the string.

11: kthx.
*/