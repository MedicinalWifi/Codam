/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/27 14:59:25 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

char	*ft_strdup(const char *s1)
{
	char *result;
	size_t i;
	size_t	strlen;

	i = 0;
	strlen = ft_strlen((char *)s1) + 1;
	result = (char *)malloc(strlen * sizeof (char));
	result = ft_memcpy(result, (const void *)s1, strlen);
	return (result);
}
/* #include <unistd.h>

int main (void)
{
	char *newstr;

	newstr = ft_strdup("hello");
	printf("The memory was copied to %p, and holds the following data: \n \"%s\". \n", newstr, newstr);
	free(newstr);
	int i;
	i = 126956;
	printf("it free\n");
	write(1, newstr, 1000);
	printf("%i\n", i);
	return (0);
}
 */