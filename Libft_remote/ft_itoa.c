/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:35:03 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/01 12:02:49 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putnbr(int n, int i, int ii);
char	*ft_itoa(int n);

char	*ft_itoa(int n)
{
	char	*result_make;
	char	*result_write;
	size_t	i;
	size_t	int_len;
	int		ii;

	if (n == -2147483648)
	{
		result_make = "-2147483648";
		return (result_make);
	}
	i = 0;
	ii = 0;
	result_make = ft_putnbr(n, i, ii);
	int_len = ft_strlen(result_make) + 1;
	result_write = malloc(int_len + 1);
	if (result_write == NULL)
		return (NULL);
	return (result_write);
}

char	*ft_putnbr(int n, int i, int ii)
{
	char	*result;

	result = NULL;
	if (n < 0 && ii == 0)
	{
		result[i] = '-';
		ii++;
		ft_putnbr(n, i, ii);
	}
	else if (n > 9)
	{
		i++;
		result[i] = *ft_putnbr(n / 10, i, ii);
		result[i] = *ft_putnbr(n % 10, i, ii);
	}
	else
	{
		i++;
		result[i] = '0' + n;
		return ((char *)result);
	}
	return (NULL);
}
