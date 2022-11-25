/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_putstr_fd.c									 :+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:47:16 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:47:24 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

/* Function name ft_putstr_fd
Prototype 			void ft_putstr_fd(char *s, int fd);
Turn in files		-
Parameters 			s: The string to output.
					fd: The file descriptor on which to write.
Return value 		None
External functs. 	write
Description 		Outputs the string ’s’ to the given file
					descriptor. */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		write (fd, &c, 1);
		i++;
	}
}
