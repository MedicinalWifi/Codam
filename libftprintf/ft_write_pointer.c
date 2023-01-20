/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_pointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 13:46:57 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/20 14:54:38 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // FOR TEST, REMOVE

void	ft_write_pointer(void *data, int *str_ln);
char	*ft_itoa1(int n);
size_t	ft_strlen1(const char *s);


void	ft_write_pointer(void *data, int *str_ln)
{
	unsigned int	*value;
	char			*hex_key;
	int				i_h;
	char			c;
	
	c = 'a';
	value = (unsigned int *)data;
	if (!value)
	{
		write(1, "null.", 5);
		return ;
	}
	hex_key = "0123456789abcdef";
	i_h = 0;
	write(1, "0x", 2);
	while (value[i_h])
	{
		c = hex_key[value[i_h] % 16];
		write(1, &c, 1);
		i_h++;
		*str_ln += 1;
	}
	*str_ln += 2;
	return ;
}
/* void	ft_write_pointer(void *data, int *str_ln)
{
	char			*s;
	unsigned int	*value;
	char			*hex_key;
	int				i_h;
	
	value = (unsigned int *)data;
	if (!value)
	{
		write(1, "null.", 5);
		return ;
	}
	i_h = 0;
	printf("the current value of i_h is: %i\n", i_h);
	hex_key = "0123456789abcdef";
	write(1, "0x", 3);
	s = ft_calloc(i_h + 1, (sizeof(char)));
	if (!s)
		return ;
	printf("\n The current content of 's' is: '%s\n", s);
	while (value[i_h])
	{
		s[i_h] = hex_key[value[i_h] % 16];
		printf("the current value is: '%u'.\n", value);
		value = value / 16;
		i_h++;
	}
	*str_ln += (ft_strlen(s) + 7);
	write(1, s, ft_strlen(s));
	free(s);
	return ;
} */

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	free((void *)s);
	return (i);
}
