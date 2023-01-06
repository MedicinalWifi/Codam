/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 11:06:22 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/06 12:58:34 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_write_char(const char *format, int i, va_list ptr_copy)
{
	char c;
	char *s;
	if (format[i] == 'c')
	{
		c = va_arg(ptr_copy, char);
		write(1, &c, 1);
	}
	if (format[i] == 's')
	{
		s = malloc((ft_strlen(va_arg(ptr_copy, char *))) * (sizeof(char)));
		if (!s)
			return;
		s = va_arg(ptr_copy, char *);
		write(1, s, ft_strlen(s));
		free(s);
	}
	return;
}