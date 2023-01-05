/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:21:42 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 14:59:08 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Program name 	libftprintf.a
Turn in files 		Makefile, *.h, /* /*.h, *.c, /* /*.c
Makefile 			NAME, all, clean, fclean, re
External functs. 	malloc, free, write,
					va_start, va_arg, va_copy, va_end
Libft authorized 	Yes
Description 		Write a library that contains ft_printf(), a
					function that will mimic the original printf()
					You have to recode the printf() function from libc.

The prototype of ft_printf() is:
int ft_printf(const char *, ...);

Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository */
#include <stdarg.h>

char *findtype(const char *format, int i);
int	ft_printf(const char *format, ...);

int	ft_printf(const char *format, ...)
{
	char *type;
	int i;
	
	type = ft_calloc(13, sizeof(char));
	if (!type)
		return(0);
		
	//first figure out if there are variables in the character string. 
	while (format[i])
	{
		if (format[i] == '%' && format[i++] != '%')
		{
			type = findtype(format, i);
			ft_write_variable(format, type)
		}
		else 
			write(1, format[i], 1);
		i++;
	}
	
}

char *findtype(const char *format, int i)
{
	i++;
	if (format[i] == 'c')
		return ("char");
	if (format[i] == 's')
		return ("char *")
	if (format[i] == 'p')
		return ("void *");
	if (format[i] == 'd')
		return ("float");
	if (format[i] == 'i')
		return ("int");
	if (format[i] == 'u')
		return ("unsigned int");
	if (format[i] == 'x')
		return ("hex");
	if (format[i] == 'X')
		return ("HEX");
	else
		return ("");
}

void ft_write_variable(const char *format, char *type)
{
	char c;
	char *s;
	void *p;
	va_list ptr;
	if (strcmp(type, "char") == 0)
	{
		c = va_arg(ptr, char);
		write(1, &c, 1);
	}
	if (strcmp(type, "char *") == 0)
	{
		s = va_arg(ptr, char *);
		write(1, s, ft_strlen(s));
	}
	if (strcmp(type, "void *") == 0)
	{
		s = "voidpointerlol";
		write(1, s, ft_strlen(s));
	}
	else
		ft_write_variable2(format, type);
	return;
}

void ft_write_variable2(const char *format, char *type)
{
	float d;
	int i;
	unsigned int u;
	va_list ptr;

	if (strcmp(type, "float") == 0)
	{
		d = va_arg(ptr, float);
		write(1, &d, 1);
	}
	if (strcmp(type, "char") == 0)
	{
		c = va_arg(ptr, char);
		write(1, &c, 1);
	}
	if (strcmp(type, "char") == 0)
	{
		c = va_arg(ptr, char);
		write(1, &c, 1);
	}
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