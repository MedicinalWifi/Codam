/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   ft_putendl_fd.c									:+:	:+:			*/
/*													 +:+					*/
/*   By: lhop <lhop@student.codam.nl>				 +#+					 */
/*												   +#+					  */
/*   Created: 2022/10/31 15:46:55 by lhop		  #+#	#+#				 */
/*   Updated: 2022/10/31 15:47:53 by lhop		  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	while (s[i])
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
	c = '\n';
	write(fd, &c, 1);
}
