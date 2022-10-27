/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:43:38 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/27 15:05:21 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

#include <strings.h>

int main(void)
{
	char *str;
	str = ft_strdup("hello");
	ft_bzero(str, 6);
	printf("The data stored is now '%s'.\n", str);
	return(0);
}
