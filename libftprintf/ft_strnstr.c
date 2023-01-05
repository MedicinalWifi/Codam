/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:10:23 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:31:11 by lhop          ########   odam.nl         */
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
#include "libftprintf.h"

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
1: I created loop iterators set to 'i', and 'i2'. 'i' is for iterating 
through the haystack, 'i2' is for iterating through the needle. 

2: I make an if statement set to the condition of needle length being 
less or equal to 0. If that's true, I return the haystack typecasted
as a char array, as per manual.

3: I create a whileloop to the condition of 'i' + 1 being less or equal
to 'len', which means we should still search. Also 'i' being less or 
equal to the length of the haystack, at the end of which there would
be no point searching. 

4: I nested another whileloop to the condition of haystack and needle
being equal, and i being less or equal to len. 

I iterate both 'i' and 'i2' up while they still are equal, and add in
an if statement to the condition of 'i2' matching the needle's
stringlength, in which case the string would have been found in its 
entirety. It then returns a pointer to the location of haystack, 
adding the current iteration of 'i', but subtracting the stringlength
of the needle, because that has just been iterated through in its entirety.
That leaves you at the exact spot where the string started.

5: In case the whileloop ends before 'i2' has reached the needle's 
stringlength, I redefine 'i' to start searching again 1 spot
after where it last started finding the string. I set i2 to 0, so it
can start searching from the 1st position again.

6: If the string is never found, I return 'NULL'.

7: kthx.
*/