/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset_U.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:46 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 12:23:10 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void *ft_memset(void *b, int c, size_t len)
{
    size_t i;
    i = 0;

    while(i <= len)
    {
        ((unsigned char *)b)[i] = ((unsigned char*)c);
        i++;
    }
    return((void*)b);
}

/*
memset: we're trying to copy a character into the destination string b. 
it's only one character that is repeated as many times as set by size_t len.

1: I create an index.

2: I open a while-loop; it exits when the index exceeds the set length.

3: I convert void *b into an unsigned char, and reassign it the value of int c.

4: I return a pointer to the memory area for the new string.

5: kthx.
*/