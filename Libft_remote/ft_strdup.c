/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/04 10:44:03 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
