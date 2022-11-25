/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:35:03 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/22 13:06:39 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_itoa
Prototype 				char *ft_itoa(int n);
Turn in files			-
Parameters 				n: the integer to convert.
Return value 			The string representing the integer.
						NULL if the allocation fails.
External functs. 		malloc
Description 			Allocates (with malloc(3)) and returns a string
						representing the integer received as an argument.
						Negative numbers must be handled. */
#include "libft.h"

char			*ft_itoa(int n);
static int		ft_nbr_len(long n);

char	*ft_itoa(int n)
{
	char			*result;
	size_t			nbr_len;
	long			num;

	num = n;
	nbr_len = ft_nbr_len(num);
	result = malloc((nbr_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		num = (num * -1);
		result[0] = '-';
	}
	result[nbr_len] = '\0';
	if (num == 0)
		result[0] = '0';
	nbr_len = nbr_len - 1;
	while (num > 0 && nbr_len >= 0)
	{
		result[nbr_len] = ((num % 10) + '0');
		num = num / 10;
		nbr_len--;
	}
	return (result);
}

static int	ft_nbr_len(long n)
{
	size_t	i;

	i = 0;
	if (n == -2147483647 -1)
		return (11);
	if (n == 0)
		return (1);
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
	return (i);
}

/* int main(void)
{
	long long a = 0;
	printf("My itoa: %s\n", ft_itoa(a));
	a = -2147483648LL;
	printf("My itoa: %s\n", ft_itoa(a));
	a = -623;
    printf("My itoa: %s\n", ft_itoa(a));
	a = 156;
	printf("My itoa: %s\n", ft_itoa(a));
	return(0);
} */