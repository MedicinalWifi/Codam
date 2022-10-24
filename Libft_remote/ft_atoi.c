/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:25 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 18:10:11 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_checkspace(const char *str);
int	ft_checkplusminus(const char *str, int i);
int	ft_numstart(const char *str);
int	ft_makenum(const char *str, int numstart, int posneg);

int	ft_atoi(const char *str)
{
	int	*result;
	int i;
	int posneg;
	int num;
	int numstart;
	
	i = ft_checkspace(str);
	posneg = ft_checkplusminus(str, i);
	numstart = ft_numstart(str);
	num = ft_makenum(str, numstart, posneg);
	
	return (num);
}

int	ft_makenum(const char *str, int numstart, int posneg)
{
	int i;
	int num;

	num = 0;
	i = numstart;
	while (str[i] > '0' && str[i] < '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * posneg);
}

int	ft_numstart(const char *str)
{
	int i;

	i = 0;
	while (str[i] < '0' || str[i] > '9')
	{
		i++;
	}
	return (i);
}

int	ft_checkplusminus(const char *str, int i)
{
	int tally;
	tally = 0;
	while (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
		{
			tally++;
		}
		i++;
	}
	if ((tally % 2) == 0)
		return (1);
	else
		return (-1);
}

int	ft_checkspace(const char *str)
{
	int	i;
	
	i = 0;
	while ((int)str[i] < 33)
	{
		i++;
	}
	return (i);
}

int main(void)
{
  int num;
  num = ft_atoi("    +---+--2987adlskja");
	printf("The converted integer is %i.\n", num);
  return (0);
}