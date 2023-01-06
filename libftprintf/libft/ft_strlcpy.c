/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:56:13 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:30:52 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings with
     the same input parameters and output result as snprintf(3).  They are
     designed to be safer, more consistent, and less error prone replacements
     for the easily misused functions strncpy(3) and strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer and
     guarantee NUL-termination if there is room.  Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst,
     NUL-terminating the result if dstsize is not 0.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal han-
     dler safety (snprintf(3) is not entirely safe on some systems), the fol-
     lowing two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() and strlcat() functions return the total
     length of the string they tried to create.  For strlcpy() that means the
     length of src.  For strlcat() that means the initial length of dst plus
     the length of src.

     If the return value is >= dstsize, the output string has been truncated.
     It is the caller's responsibility to handle this. */
#include "libftprintf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (i + 1 < dstsize && src[i] != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

/* 
1: I create a loop interator, and set to 0.

2: I create an if function with the condition that dstsize is less than one. 
If that condition is met, i return the src without copying, because copying
in that case is not possible.

3: I open a while loop on the condition that i + 1 is less than dstsize. 
this to make sure that i only copy dstsize - 1. the loop will stop when 
i is 1 below dstsize, because we artificially added 1 to i in the condition.
this is to leave space for null terminating character. 

4: I overwrite the value pointed to by dst[i], with the value pointed 
to by src[i].

5: I set 'i' to move increase by 1 after the overwrite is complete. 

6: When the loop has written src content into the dst, into all but 1 spots,
(dstsize-1), I then write the null terminating character. "\0"

7: I then return a call to strlen with 'src' in the parameter, so that 
this function will return the length of the string 'src'. 

8: kthx.
*/ 