/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:56 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/28 11:43:13 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	i;
	size_t	strlen;

	i = 0;
	strlen = ft_strlen((char *)s1) + 1;
	result = (char *)malloc(strlen * sizeof (char));
	result = ft_memcpy(result, (const void *)s1, strlen);
	return (result);
}
