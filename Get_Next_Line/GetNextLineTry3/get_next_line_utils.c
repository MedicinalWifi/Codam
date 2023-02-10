/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 15:49:37 by lhop          #+#    #+#                 */
/*   Updated: 2023/02/10 16:08:42 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int i;
	
	i = 0;
	if (!string)
		return(0);
	if (string[0] != '\0')
	{
		while (string[i] != '\0')
		{
			i++;
		}
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*result;
	size_t		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (NULL);
	while (i <= count)
	{
		*(char *)(result + i) = '\0';
		i++;
	}
	return (result);
}