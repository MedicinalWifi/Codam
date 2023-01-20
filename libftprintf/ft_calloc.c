/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:41:36 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
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
#include "ft_printf.h"

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
} 

1: I create a void pointer. I make it void, because void can contain any
datatype. 

2: I allocate memory to the pointer by using malloc, taking 'count', 
'size'. Count is for the amount of objects, size of for bytesize of the 
object. If I wanted space for 5 chars, I could write count = 5, 
size = sizeof(char), which would automatically give me the correct
amount of bytes.

3: I make a malloc protection: if ptr == NULL, this means allocation
failed and I will now end my function. 

4: I then use my function 'bzero', to write '\0' in the pointer's 
location. 

5: I return the pointer, pointing towards memory space that has 
a specified amount of \0s in it.

6: kthx.
*/