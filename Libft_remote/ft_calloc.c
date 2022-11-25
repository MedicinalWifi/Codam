/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:36 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/22 13:07:24 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* void *calloc(size_t count, size_t size); 
 DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
     allocate memory.  The allocated memory is aligned such that it can be
     used for any data type, including AltiVec- and SSE-related types.  The
     aligned_alloc() function allocates memory with the requested alignment.
     The free() function frees allocations that were created via the preceding
     allocation functions.

     The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero.
RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and
     aligned_alloc() functions return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer and set errno to ENOMEM.*/
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
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