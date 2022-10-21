/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:35 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 14:28:23 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    i = 0;

    while (i <= n)
    {
        if(s[i] == c)
        {
            return((const void*)s[i]);
        }
        i++;
    }
    return (NULL);
}

/* 
memchr: this returns a pointer to memory where int c occurred in string s.

1: I create an index to move through the string.

2: I create a whileloop on the condition of index being less than n.

3: while it is searching, it could hit my if under the condition s[i] == c.
In that case, a pointer to the memory location is returned.

4: if the while loop finishes without a match, NULL is returned.

5: kthx.
 */