/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 11:34:13 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/06 14:41:25 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_write_int(const char *format, int i, va_list ptr)
{
	char *s;
	float f;
	if (format[i] == 'i')
	{
		s = malloc((ft_strlen(ft_itoa(va_arg(ptr, int)))) * (sizeof(char)));
		if (!s)
			return;
		s = ft_itoa(va_arg(ptr, int));
		write(1, &s, ft_strlen(s));
		free(s);
	}
	if (format[i] == 'd')
	{
		s = malloc((ft_strlen(ft_itoa(va_arg(ptr, int)))) * (sizeof(char)));
		if (!s)
			return;
		
		f = va_arg(ptr, float);
		s = ft_floattostring(f);
		write(1, &s, ft_strlen(s));
		free(s);
	}
	return;
}

char *ft_floattostring(float f)
{
	char		*whole;
	char		*predecimal;
	char		*postdecimal;
	int			i;
	int			numsize;
	
	numsize = ft_countnumsize(f);
	predecimal = malloc(ft_strlen(ft_itoa(f)) * sizeof(char));
	postdecimal = calloc(6, sizeof(char));
	whole = calloc((ft_strlen(ft_itoa(f)) + 7), sizeof(char));
	if (!predecimal || !postdecimal || !whole)
		return(NULL);
	predecimal = ft_itoa(f);
	postdecimal = multiplyfloat(f, postdecimal, numsize);
	strlcat(whole, predecimal, (size_t)numsize + 1);
	strlcat(whole, postdecimal, (size_t)numsize + 7);
    return(whole);
}

int	ft_countnumsize(float f)
{
    int numsize;
    numsize = 0;
	int i;
	i = f;
    
    while (i > 0)
    {
    	i = i / 10;
        numsize++;
    }
	return(numsize);
}

char *ft_multiplyfloat(float f, char *postdecimal, int numsize)
{
	char *wholenumber;
	int wholenumbersize;
	int	pd_i;
	int	wn_i;
	
	pd_i = 1;
	wn_i = numsize;
	wholenumber = calloc(20, sizeof(char));
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
	return(postdecimal);
}