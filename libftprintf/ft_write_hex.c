/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 11:34:04 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/06 13:07:12 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_write_hex(const char *format, int i, va_list ptr)
{
	char c;
	char *s;

	if (strcmp(type, "char") == 0)
	{
		c = va_arg(ptr, char);
		write(1, &c, 1);
	}
	if (strcmp(type, "char *") == 0)
	{
		s = malloc((ft_strlen(va_arg(ptr, char *))) * (sizeof(char)));
		if (!s)
			return;
		s = va_arg(ptr, char *);
		write(1, s, ft_strlen(s));
	}
	return;
}