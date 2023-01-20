/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:08:45 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/20 12:14:29 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
     The strlen() function computes the length of the string s.  The strnlen()
     function attempts to compute the length of s, but never scans beyond the
     first maxlen bytes of s.

RETURN VALUES
     The strlen() function returns the number of characters that precede the
     terminating NUL character.  The strnlen() function returns either the
     same result as strlen() or maxlen, whichever is smaller. */
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* 
1: I created a loop iterator called 'i', to iterate through the 
elements of the array.

An array is a set of datapoints grouped together, in this case it is an 
array of chars, passed as a pointer. Meaning, this variable points to 
the memory space coupled to it elsewhere. 
Otherwise, it would look like 's[]' or s[i]', in which 'i' can be a 
variable or an actual number. An actual number would tell you how many 
elements the array has. s[5] has 6 elements(counting 0), and could for 
example contain: "h, e, l, l, o, \0". s[0] = 'h', s[2] = 'l'.

2: I open a while loop, which will keep applying the code within the
brackets, as long as the terminating \0 character has not been reached 
in the array. Arrays should always end with '\0'.

3: In the while loop, I increase 'i' by 1 every 'iteration' of the loop.
I do this by using '++' operator. 

How do I know that the '\0' character is reached?
Inside the while condition, i included 's[i]'. I set 'i' to 0 before 
the loop, and inside the condition i use 'i' to represent which element
of 's' we should be looking at. we start by looking at element 's[0]', 
and as long as the elements are not '\0', the 'i' loop iterator will 
increase by 1. the second loop we would look at 's[1]', and so forth.
At some point, 's[i]' will contain '\0', and the loop will end. 

4: I then return the size of my loop iterator 'i', which tells you how many
elements the while loop passed when the computer found the '\0'.

5: kthx.
*/