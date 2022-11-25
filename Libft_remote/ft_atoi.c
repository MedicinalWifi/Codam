/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:25 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/22 13:07:08 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* int atoi(const char *str);
 DESCRIPTION
     The atoi() function converts the initial portion of the string pointed to
     by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

     While the atoi() function uses the current locale, the atoi_l() function
     may be passed a locale directly. See xlocale(3) for more information.
	  */
#include "libft.h"

static int	ft_checkspace(const char *str);
static int	ft_checkplusminus(const char *str, int i);
static int	ft_makenum(const char *str, int numstart, int posneg);

int	ft_atoi(const char *str)
{
	int	i;
	int	posneg;
	int	num;

	i = ft_checkspace(str);
	posneg = ft_checkplusminus(str, i);
	if (!str)
		return (0);
	if (posneg < -1)
		return (0);
	if (str[i] == '+' || str[i] == '-')
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

static int	ft_makenum(const char *str, int i, int posneg)
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

static int	ft_checkplusminus(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		return (1);
	if (str[i] >= '0' || str[i] <= '9')
		return (1);
	else
		return (-2);
}

static int	ft_checkspace(const char *str)
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