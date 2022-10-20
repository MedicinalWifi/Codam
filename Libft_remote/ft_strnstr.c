/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:29:46 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/20 12:48:13 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char ft_strnstr(const char *hay, const char *needle, int len)
{
    int i;
    int nlen;
    i = 0;
    nlen = ft_strlen(*needle);

    if (nlen < 1)
    {
        return(*hay);
    }
    else
    {
        int ni;
        ni = 0;
        while (*hay[i] != \0 && i <= len)
        {

            while (hay[i] == needle[ni] && i <= len)
            {
                if (ni == nlen)
                {
                    i -= nlen;
                    return ((char*)hay[i]);
                }
                i++;
                ni++;
            }
            ni = 0;
            i++;
        }
        return (NULL);
    }
}
/*
1: I created an index to count the places in the haystack.

2: I created an index, nlen, to know the length of needle.

3: I create a condition to check if the search query is empty.
In that case, the whole haystack is returned.

4: I create an index for moving through the needle. 

5: I create a while loop to check the hay until null or length 
is reached. 

6: I create another whileloop that compares hay to needle.

7: If the needle index reaches its full length while in the
comparison loop, I return a pointer to the start of the needle.
(i - nlen)

8: If it exits the loop before nlen was completed, I reset
needle index to 0, so that the previous whileloop can keep
searching for the needle from its starting point again.

9: if the whileloop ends before the needle is found, 
NULL is returned. 

10: kthx.
*/