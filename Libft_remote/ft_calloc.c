/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:36 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/27 15:06:18 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	ptr = malloc(count * size);
	bzero(ptr, count * size);
	return (ptr);
}

/* int main(void)
{
	size_t count;
	size_t size;

	count = 5;
	size = 5;
} */
/* 
Calloc: allocating contiguous memory for count objects of specific size.
This means it allocates connected memory slots for a certain amount of objects
of a specified size.

The memory slot's content will be '\0' bytes written to fill.

It returns a pointer to the start of the allocated memory.
*/