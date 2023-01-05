/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:21:42 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:50:53 by lhop          ########   odam.nl         */
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

int	ft_printf(const char *format, ...)
{
	va_list ptr;
	char *type;
	int i;
	
	//first figure out if there are variables in the character string. 
	while (* != )
	va_start(va_list ptr, const char input);
	type = findtype(const char *input, i);
	va_arg(va_list ptr, type);
	
	va_end(va_list ptr);
	
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
		- Iterates through the character string
		- Stops when it finds a variable specifier.
		- Prints the data in the format specified.
		- Continues until the end of the string.
	
 */