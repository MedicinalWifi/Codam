/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:10:23 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/22 11:23:28 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
     The strstr() function locates the first occurrence of the null-terminated
     string needle in the null-terminated string haystack.

     The strcasestr() function is similar to strstr(), but ignores the case of
     both strings.

     The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the string haystack, where not more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.

     While the strcasestr() function uses the current locale, the
     strcasestr_l() function may be passed a locale directly. See xlocale(3)
     for more information.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned. */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (ft_strlen(needle) <= 0)
		return ((char *)haystack);
	while (i + 1 <= len && i <= (ft_strlen(haystack)))
	{
		while (haystack[i] == needle[i2] && i + 1 <= len)
		{
			while (haystack[i] == needle[i2] && i + 1 <= len)
			{
				i2++;
				i++;
				if (i2 == (ft_strlen(needle)))
					return ((char *)(haystack + (i - ft_strlen(needle))));
			}
			i = (i - i2) + 1;
			i2 = 0;
		}
		i++;
	}
	return (NULL);
}
/*
1: I created an index, i, to count the places in the haystack.

2: I created an index, i2, to count places in the needle.

3: I created a variable for the hay length

4: I craeted a variable for the needle length.

5: I created a variable for the string detection spot.

6: I set all my indexes to 0

7: I find the lengths of the hay and the needle.

8: I set a condition for if the needle is empty, in which case
it returns the whole haystack.

9: I create my first while loop, to the condition of i + 1 being 
less or equal to len. We only want to search for len amount of chars.
Len however, is a size_t, which is a format that starts at 1 instead
of 0. I've set my own size_t to start at 0, so I use 'i + 1' to have 
the the len and i refer to the same spot.

The second condition is i being less than hay_len, which is the
length of the string we're searching.

10: In this while-loop, I put a second while loop, 
to the condition of hay[i] being equal to needle[i2].
i2 is 0, so it starts at the beginning of the needle string.
Another condition is while i + 1 is still less than len.
I immediately mark the spot with 'check', to know where
it started being the same.

11: this will keep searching and iterating up, as long as they 
are equal.

12: if at some point i2 is equal to needle-len, this means the 
entire string was found. The original checkpoint is then returned.

13: if they are no longer equal, 


*/