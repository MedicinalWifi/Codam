/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:08:45 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/28 14:36:16 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* 
strlen: we're trying to find the length of a string.

1: i created an index, to cycle through
the string.

2: I open a while loop, which 
will keep applying the operation within as 
long as the \0 characte has not been reached.

3: As i do this, i am increasing the size of my
index by 1, every time another place 
has been found that is not \0. 

4: i then return the size of my index, which
tells you how long the string was before the
terminating character.

5: kthx.
*/