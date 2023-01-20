/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 11:34:04 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/20 15:01:22 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_int_to_hex(char *s, unsigned int value, const char *format, int i);
void	ft_write_hex(const char *format, int i, unsigned int data, int *str_ln);

void	ft_write_hex(const char *format, int i, unsigned int data, int *str_ln)
{
	char			*s;

	s = ft_calloc(8, (sizeof(char)));
	if (!s)
		return ;
	ft_memcpy(s, (ft_int_to_hex(s, data, format, i)), 8);
	*str_ln += ft_strlen(s) - 1;
	write(1, s, ft_strlen(s));
	free(s);
	return ;
}

char	*ft_int_to_hex(char *s, unsigned int data, const char *format, int i)
{
	char	*hex_key;
	int		i_h;

	
	i_h = 8;
	if (format[i] == 'x')
		hex_key = "0123456789abcdef";
	else
		hex_key = "0123456789ABCDEF";
	while (i_h >= 0)
	{
		printf("s[i_h] = %c\n", s[i_h]);
		s[i_h] = hex_key[data % 16];
		printf("s[i_h] = %c\n", s[i_h]);
		data = data / 10;
		printf("data: %u\n", data);
		i_h--;
	}
	free(hex_key);
	return (s);
}
