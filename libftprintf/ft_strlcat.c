/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:34:33 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:30:47 by lhop          ########   odam.nl         */
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
	 
     strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.

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
     It is the caller's responsibility to handle this.
	  */
#include "libftprintf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	i2;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
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
1: First I create placeholders for the string-lengths of both source and 
destination. I fill those using the strlen function. 

2: I create an if statement for the condition where dstsize is smaller than
dst_len. This would mean that the length of the dst string is longer than 
the length of the destination that src and dst will be copied into, so none of 
the src could be copied. In that case, i just return the length of the string 
that was supposed to be created, and do nothing more.

3: Then, I set my 'i' loop iterator to dst_len, because I want the 
concatenation of src to dst to start at the end of the dst string. I set my 
second loop iterator 'i2' to 0, because I will use it to iterate from the 
start of src. 

4: I open a whileloop to the condition of the value pointed to at the address
of 'src + i2' not being '\0', and i2 being lower than src_len, which would 
mean the end of the string. Also 'i' having to be less than dstsize - 1.

5: During every successive loop, I am coping the data at the adress of src + i2
into the adress of dst + i. 

6: when the while-loop ends, I am writing '\0' as the terminating character. 

7: I then return dst_len + src_len, after having concatonated the two 
in dst.

8: kthx.

*/