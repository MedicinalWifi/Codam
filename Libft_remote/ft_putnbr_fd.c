/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_putnbr_fd.c									 :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:46:29 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:47:58 by lhop		  ########   odam.nl		 */
/*																			*/
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
#include "libft.h"

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
