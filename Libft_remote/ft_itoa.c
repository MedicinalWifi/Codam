/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:35:03 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/11 15:29:08 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <stdio.h> */

char	*ft_itoa(int n);
int		ft_nbr_len(int n);

char	*ft_itoa(int n)
{
	char		*result;
	int			nbr_len;
	long long	num;

	num = n;
	nbr_len = ft_nbr_len(num);
	if (!(result = ft_calloc((nbr_len + 1), sizeof(char))))
		return (NULL);
	if (num == -2147483648)
		return(result = "-2147483648");
	if (num < 0)
	{
		num = (num * -1);
		result[0] = '-';
	}
	nbr_len = nbr_len - 1;
	while (num > 0 && nbr_len >= 0)
	{
		result[nbr_len] = ((num % 10) + '0');
		num = num / 10;
		nbr_len--;
	}
	return (result);
}

int		ft_nbr_len(n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return(11);
	if (n <= 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}

/* 
int main(void)
{
  int a = 812;
  printf("%s", ft_itoa(a));
  return(0);
} */