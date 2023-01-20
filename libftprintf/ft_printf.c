/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 14:21:42 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/20 14:58:02 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // for illegal printf
#include <limits.h> // for testing LONG_MIN & LONG MAX

int		ft_printf(const char *format, ...);
void	ft_redirectfortype(const char *format, int i, va_list ptr, int *str_ln);

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ptr;
	int		str_len;
	int		*str_ln;

	va_start(ptr, format);
	i = 0;
	str_len = 0;
	str_ln = &str_len;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ft_redirectfortype(format, i, ptr, str_ln);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			str_len++;
		}
	}
	va_end(ptr);
/* 	printf("My returned strlen is: %i.\n", str_len); */
	return (str_len);
}

void	ft_redirectfortype(const char *format, int i, va_list ptr, int *str_ln)
{
	i++;
	if (format[i] == 'c')
		ft_write_char((char)(va_arg(ptr, int)), str_ln);
	else if (format[i] == 's')
		ft_write_string(va_arg(ptr, char*), str_ln);
	else if (format[i] == 'i' || format[i] == 'd')
		ft_write_int(format, i, va_arg(ptr, int), str_ln);
	else if (format[i] == 'u')
		ft_write_int(format, i, va_arg(ptr, unsigned int), str_ln);
	else if (format[i] == 'p')
		ft_write_pointer(va_arg(ptr, void*), str_ln);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_write_hex(format, i, va_arg(ptr, unsigned int), str_ln);
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		*str_ln += 1;
	}
	else
		*str_ln -= 1;
	return ;
}


int	main(void)
{
	char	c;
	char	b;
	int 	strlen;

	c = 'a';
	b = 'z';
	/* ft_printf("My printf shows the char 'a' to be: '%c'.\n", c);
	strlen = printf("OG printf shows the char 'a' to be: '%c'.\n", c);
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows test string with percentage as: '%'.\n");
	strlen = printf("OG printf shows test string with percentage as: '%'.\n");
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows: '%hytest'\n");
	strlen = printf("OG printf shows: '%hytest'.\n");
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows: '%x'.\n", 2147483647);
	strlen = ft_printf("My printf shows: '%x'.\n", 2147483647);
	printf("My Printf Strlen: '%i'\n", strlen);
	strlen = printf("OG printf shows: '%x'.\n", 2147483647);
	printf("OG Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows: '%d'.\n", 21474);
	strlen = printf("OG printf shows: '%d'.\n", 21474);
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows: '%d', and then '%d'.\n", 21474, 2148);
	strlen = printf("OG printf shows: '%d', and then '%d'.\n", 21474, 2148);
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows: '%d', and then '%d'.\n", -21474, 2148);
	strlen = printf("OG printf shows: '%d', and then '%d'.\n", -21474, 2148);
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("My printf shows: '%p', '%p'.\n", &c, &b);
	strlen = printf("OG printf shows: '%p', '%p'.\n", &c, &b);
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");
	
	ft_printf("%c%c%c\n", 'a', '\t', 'b');
	strlen = printf("%c%c%c\n", 'a', '\t', 'b');
	printf("Original Printf Strlen: '%i'\n", strlen);
	printf("\n");

	ft_printf("My printf returning a null pointer string: %s\n", (char *)NULL);
	strlen = printf("My printf returning a null pointer string: %s\n", (char *)NULL);
	printf("OG printf returning a null pointer string: %s\n", (char *)NULL);
	printf("\n");
 */

	printf("OG printf showing a pointer with a weird format: %p\n", -4);
	ft_printf("My printf showing a pointer with a weird format:\n %p\n", -1);
	printf("\n");
	ft_printf("My printf showing a pointer with a weird format:\n %p \n %p \n", LONG_MIN, LONG_MAX);
	printf("OG printf showing a pointer with a weird format: %p %p \n", LONG_MIN, LONG_MAX);
	return (0);
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