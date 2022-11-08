/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:10:23 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/07 18:07:01 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	hay_len;
	size_t	needle_len;
	char	*check;

	i = 0;
	i2 = 0;
	hay_len = ft_strlen(hay);
	needle_len = ft_strlen(needle);
	if (needle_len <= 0)
		return ((char *)hay);
	while (i + 1 <= len && i < hay_len)
	{
		while (hay[i] == needle[i2] && i + 1 <= len)
		{
			check = ((char *)hay + i);
			while (hay[i] == needle[i2] && i + 1 <= len)
			{
				i2++;
				i++;
				if (i2 == needle_len)
					return (check);
			}
			i2 = 0;
		}
		i++;
	}
	return (NULL);
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