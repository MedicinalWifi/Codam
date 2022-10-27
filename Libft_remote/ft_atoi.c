/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:25 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/27 14:03:31 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkspace(const char *str);
int	ft_checkplusminus(const char *str, int i);
int	ft_numstart(const char *str);
int	ft_makenum(const char *str, int numstart, int posneg);

int	ft_atoi(const char *str)
{
	int	i;
	int	posneg;
	int	num;

	i = ft_checkspace(str);
	posneg = ft_checkplusminus(str, i);
	i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		num = ft_makenum(str, i, posneg);
		return (num);
	}
	else
	{
		return (0);
	}
}

int	ft_makenum(const char *str, int i, int posneg)
{
	int	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * posneg);
}

int	ft_checkplusminus(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	else
		return (1);
}

int	ft_checkspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	return (i);
}

/* int	main(void)
{
	int	num;

	num = ft_atoi("    -29873343adlskja");
	printf("The converted integer is %i.\n", num);
	return (0);
}
 */