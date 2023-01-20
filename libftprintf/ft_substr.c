/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:36:53 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 
char *ft_substr(char const *s, unsigned int start, size_t len);
Parameters 		s: The string from which to create the substring.
				start: The start index of the substring in the string ’s’.
				len: The maximum length of the substring.
Return value 	The substring.
				NULL if the allocation fails.
External
functs. 		malloc
Description 	Allocates (with malloc(3)) and returns a substring
				from the string ’s’.
				The substring begins at index ’start’ and is of
				maximum size ’len’.
 */
#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (start >= s_len || !s || len == 0)
		return (ft_calloc(1, sizeof(char)));
	if ((s_len - start) <= len)
		substring = malloc(((s_len - start) + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len && i < s_len && start < s_len)
	{
		*(substring + i) = *(s + start);
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (s_len <= len)
		substring = malloc((s_len + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len && i < s_len && start < s_len)
	{
		*(substring + i) = *(s + start);
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
} 

1: I create a placeholder for my substring, a loop iterator called 'i', 
and a placeholder for the string length. 

2: I set the value of s_len to the stringlength of s, using strlen, and
set my loop iterator to 0.

3: I create an if statement to the condition of start being higher or 
equal to stringlength, which means the substring starts at the end of 
the string. Also if string doesn't exist, or if the length of the 
substring is 0. 

If that is the case, no substring can be created. I allocate memory 
by using calloc. This writes 1 '\0' in the allocated space.
I return the pointer created by calloc as a result.

4: I create an if statement to the condition of stringlength minus 
the start position being less than 'len', the length of the substring 
to be created. If that is true, then I need to only allocate space for
the amount of chars that are available, instead of len.
I do that by allocating the string length minus the start position.
Else, I just allocate the len plus 1 for the '\0'.

5: I add a memory protection, if substring doesn't exist, I return NULL.

6: I create a whileloop to the condition of i being less than len, 
less than stringlength, and start being less than stringlength.
I then start copying the substring into the placeholder. I'm using
start as a loop iterator to accompany 'i'. 

7: I set the final character of the substring to '\0', and then return 
the result.

8: kthx.
*/