/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:21:42 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/06 12:56:56 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
int	ft_printf(const char *format, ...);
void ft_redirectfortype(const char *format, int i, va_list *ptr_copy);

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ptr;
	va_list ptr_copy;
	
	va_start(ptr, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			ft_redirectfortype(format, i, ptr_copy);
		}
		else if (format[(i - 1)] != '%')
			write(1, &format[i], 1);
		i++;
	}
	va_end(ptr);
	return (0);
}

void ft_redirectfortype(const char *format, int i, va_list *ptr_copy)
{
	i++;
	if (format[i] == 'c' || format[i] == 's')
		ft_write_char(format, i, ptr_copy);
	if (format[i] == 'i' || format[i] == 'd' || format[i] == 'u')
		ft_write_int(format, i, ptr_copy);
	if (format[i] == 'p' || format[i] == 'x' || format[i] == 'X')
		ft_write_hex(format, i, ptr_copy);
	return;
}

/* 
1: How does a variadic function work?
A variadic function takes an unspecified amount of parameters into the 
parameter list.
2: What does printf do exactly?
	Inputs: 
		- the character string. 
		- the variables in the string.
	What it does with that info:
		- Iterates through the character string.
		- Stops when it finds a variable specifier.
		- Prints the data in the format specified.
		- Continues until the end of the string.
		- 
 */