/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 13:44:59 by lhop          #+#    #+#                 */
/*   Updated: 2023/02/06 13:59:51 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*read_next_line(int fd, int buf_size)
{
	char			*buf;
	static int		read_pointer;
	int				i;
	
	i = 0;
	read_pointer = 0 + read_pointer + read(fd, buf, buf_size);
	while (read(fd, buf, buf_size) != 0)
	{
		read(fd, buf, buf_size);
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				return (splitbuf(buf, i));
			}
			i++;	
		}
		i = 0;
	}
} */

/* char	*splitbuf(char *buf, int i, char *terminated_buf)
{
	char	*terminated_buf;
	
	terminated_buf = malloc(i + 1 * sizeof(char));
	terminated_buf[i + 1] = '\0';
	while (i >= 0)
	{
		terminated_buf[i] = buf[i];
		i--;
	}
	return (terminated_buf);
} */