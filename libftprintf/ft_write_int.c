/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 11:34:13 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/19 15:23:23 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_int(const char *format, int i, int data, int *str_ln)
{
	char	*s;

	if (format[i] == 'i' || format[i] == 'd')
	{
		s =  ft_itoa(data);
		if (!s)
			return ;
		*str_ln += ft_strlen(s);
		write(1, s, ft_strlen(s));
		free(s);
	}
	if (format[i] == 'u')
	{
		if (data < 0)
			data *= -1;
		s =  ft_itoa(data);
		if (!s)
			return ;
		*str_ln += ft_strlen(s);
		write(1, s, ft_strlen(s));
		free(s);
	} 
	return ;
}

/* 
char	*ft_floattostring(float f, char *s);
int		ft_countnumsize(float f);
char	*ft_multiplyfloat(float f, char *postdecimal, int numsize);

char	*ft_floattostring(float f, char *s)
{
	char		*predecimal;
	char		*postdecimal;
	int			numsize;

	numsize = ft_countnumsize(f);
	predecimal = ft_calloc(ft_strlen(ft_itoa(f)), sizeof(char));
	postdecimal = ft_calloc(6, sizeof(char));
	free((void *)s);
	s = ft_calloc((ft_strlen(ft_itoa(f)) + 7), sizeof(char));
	if (!predecimal || !postdecimal)
		return (NULL);
	predecimal = ft_itoa(f);
	postdecimal = ft_multiplyfloat(f, postdecimal, numsize);
	ft_strlcat(s, predecimal, (size_t)(numsize + 1));
	ft_strlcat(s, postdecimal, (size_t)(numsize + 7));
	free((void *)postdecimal);
	free((void *)predecimal);
	return (s);
}

int	ft_countnumsize(float f)
{
	int		numsize;
	int		i;

	i = f;
	numsize = 0;
	while (i > 0)
	{
		i = i / 10;
		numsize++;
	}
	return (numsize);
}

char	*ft_multiplyfloat(float f, char *postdecimal, int numsize)
{
	char	*wholenumber;
	int		wholenumbersize;
	int		pd_i;
	int		wn_i;

	pd_i = 1;
	wn_i = numsize;
	wholenumber = ft_calloc(20, sizeof(char));
	f = f * 10000;
	wholenumber = ft_itoa(f);
	wholenumbersize = ft_strlen(wholenumber);
	postdecimal[0] = '.';
	while (wholenumber != '\0' && pd_i <= 5)
	{
		postdecimal[pd_i] = wholenumber[wn_i];
		pd_i++;
		wn_i++;
	}
	free((void *)wholenumber);
	return (postdecimal);
}

if (format[i] == 'd') // float is not a thing
	{
		f = (float)data;
		s = malloc((ft_strlen(ft_itoa(f))) * (sizeof(char)));
		if (!s)
			return ;
		s = ft_floattostring(f, s);
		*str_ln += ft_strlen(s);
		write(1, s, ft_strlen(s));
		free(s);
	} */