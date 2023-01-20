/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:56 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
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
#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	strlen;

	strlen = ft_strlen(s1) + 1;
	result = (char *)malloc(strlen * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, (const void *)s1, strlen);
	return (result);
}

/*
1: I first create a char placeholder for the result, and a placeholder
for the length of the string. 

2: I redefine strlen by using the strlen function, and add 1 for '\0'.

3: I allocate memory with malloc to the result placeholder, and 
create a protection in case the allocation fails. 

4: Then I copy the string into the result placeholder with my 
function 'memcpy'. I typecast s1 as a void pointer, because 
memory functions work with void datatypes.

5: I return my result pointer with the string duplicated inside it.

6: kthx.
*/