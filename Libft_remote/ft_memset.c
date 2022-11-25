/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:46 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/24 12:52:43 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* void *memset(void *b, int c, size_t len);

DESCRIPTION
     The memset() function writes len bytes of value c (converted to an
     unsigned char) to the string b.

RETURN VALUES
     The memset() function returns its first argument. */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = c;
		i++;
	}
	return (b);
}

/*

1: I create a loop iterator called 'i', of the datatype 'size_t'. 
I do this so that i can directly compare it to size_t len, which wouldn't
be possible if they were different datatypes.

2: I open a while-loop; it ends when the loop iterator is equal or bigger than
the value of variable 'size_t len', that was passed to the function as an
argument, in the parameter of the function call.

3: I convert void *b into an unsigned char, and reassign it the value of int c.

void pointers are used because they can turn into any datatype, which makes them
good for memory allocation. 


4: The while loop iterates through string 'void *b', for the amount of len. 
every iteration, it will change the current element of the string to 'c'. 

We don't use 'b[i]', and instead (b + i), because we are writing to a direct 
memory adress. you can see that by the '*' in front of the typecast 
'(unsigned char *)' That line typecast the void pointer as a unsigned char 
pointer, but also points to the literal adress of it. To get a higher adress, 
you then have to add i to it. Like a home in a street. number 26, plus 4 creates 
number 30. Otherwise we would be doing 'streetname 26[4]', and the adress 
itself is not an array.

5: I return a pointer to the memory area for the new string.

6: kthx.
*/