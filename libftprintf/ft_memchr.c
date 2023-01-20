/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:35 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* void *memchr(const void *s, int c, size_t n);

DESCRIPTION
     The memchr() function locates the first occurrence of c (converted to an
     unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, or NULL if
     no such byte exists within n bytes. */
#include "ft_printf.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)(s + i)) == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}

/* 

1: I create a loop iterator called 'i'.

2: I open a whileloop to the condition of i being less than 'n', 
which is the amount of memory bytes we are supposed to search.

3: I nest an if statement to the condition of s[i] being equal 
to c. 

I've done 2 things here: 
1: I have typecasted 's' to an unsigned char.
This will handle chars and also non ascii chars.
I have referred directly to the value at this address. 
2: I have typecasted int c into an unsigned char as well.

4: if that statement is true, I am returning the void pointer. 
I do this by typecasting first into a void pointer, and then 
returning the address of 's', but moving 'i' adress points further
from that point, so that I return the correct address.

5: if the while loop ends without returning a pointer, 
i return 'NULL' because the search has come up empty.

6: kthx. 
 */