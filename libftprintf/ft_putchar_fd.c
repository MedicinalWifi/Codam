/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:39:26 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_putchar_fd
Prototype 			void ft_putchar_fd(char c, int fd);
Turn in files 		-
Parameters 			c: The character to output.
					fd: The file descriptor on which to write.
Return value 		None
External functs. 	Write
Description 		Outputs the character ’c’ to the given file
					descriptor. */
#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
1: I use the write function to write char c into the fd.

2: kthx.
*/