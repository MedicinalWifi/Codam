/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:46:55 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:30:05 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name 	ft_putendl_fd
Prototype 			void ft_putendl_fd(char *s, int fd);
Turn in files 		-
Parameters 			s: The string to output.
					fd: The file descriptor on which to write.
Return value 		None
External functs. 	write
Description 		Outputs the string ’s’ to the given file descriptor
					followed by a newline. */
#include "libftprintf.h"

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

/*
1: I first create a loop iterator called 'i', and a char placeholder
called 'c'. 

2: I start a while loop to the condition of s1 not being terminated. 
While that is true, I set c to the current iteration of s1, 
then I write that iteration into the filedescriptor, and I iterate
up one spot in s1. 

3: When that has happened, i redefine c to a newline, and 
i write that newline into the filedescriptor. 

4: kthx.
*/
