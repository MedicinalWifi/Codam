/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/22 13:09:22 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* char *strdup(const char *s1);
DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the
     string s1, does the copy, and returns a pointer to it.  The pointer may
     subsequently be used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set to
     ENOMEM.

     The strndup() function copies at most n characters from the string s1
     always NUL terminating the copied string. */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	strlen;

	strlen = ft_strlen((char *)s1) + 1;
	result = (char *)malloc(strlen * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, (const void *)s1, strlen);
	return (result);
}
