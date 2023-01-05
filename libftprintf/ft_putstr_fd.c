/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:47:16 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:30:13 by lhop          ########   odam.nl         */
/*                                                                            */
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
#include "libftprintf.h"

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

/*
1: I first create a loop iterator called 'i', and a char placeholder
called 'c'. 

2: I create a while loop to the condition of s[i] not having terminated.
In this while loop I set c to the current iteration of s, and then 
write that character into the file descriptor fd. I iterate up into
the string and repeat the process until termination is reached.

3: kthx.
*/