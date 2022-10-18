/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr_UNFINISHED.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:29:46 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/13 15:33:18 by lhop          ########   odam.nl         */
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
                    return (*hay[i]);
                }
                i++;
                ni++;
            }
            i++;
        }
        return (NULL);
    }
}
/*i first created an index to count the places in the haystack.
I also created an index, nlen, to know the length of needle.
Then i create a while loop to check the hay until null or length 
is reached. Then i create a whileloop that compares hay to needle.
if */