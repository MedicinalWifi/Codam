/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:46:29 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_putnbr_fd
Prototype 			void ft_putnbr_fd(int n, int fd);
Turn in files		-
Parameters 			n: The integer to output.
					fd: The file descriptor on which to write.
Return value 		None
External functs. 	write
Description 		Outputs the integer ’n’ to the given file
					descriptor. */
#include "ft_printf.h"

static void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar('-', fd);
		nn = nn * -1;
	}
	if (nn > 9)
	{
		ft_putnbr_fd((int)(nn / 10), fd);
		ft_putnbr_fd((int)(nn % 10), fd);
	}
	else
	{
		c = '0' + nn;
		ft_putchar(c, fd);
	}
}

/*
1: I create a placeholder for char, and a placeholder for 
a long int. The long int becomes defined by n. This is to 
handle the max size.

2: I create an if statement to the condition of nn being 
less than 0, in which case I write '-' into the file descriptor
and turn the number positive after. For this reason, 
it will only happen once. 

3: I create an if statement to the condition of nn being 
over 9, at which point I pass the number back into the function
divided by 10, until that is no longer possible, at which point 
it returns the modular. 

4: This recursive function will then pass the individiual numbers
to ft_putchar, which will write them into the file descriptor.
The first parameter of the write function takes the destination
of the character to be written, the second the location
of the data to be written, and the third the amount of bytes
to be written.

5: kthx.
*/