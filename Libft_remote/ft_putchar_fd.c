/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_putchar_fd.c									:+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:39:26 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:47:48 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
