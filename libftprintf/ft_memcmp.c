/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:38 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* int memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.
     Both strings are assumed to be n bytes long.

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical, oth-
     erwise returns the difference between the first two differing bytes
     (treated as unsigned char values, so that `\200' is greater than `\0',
     for example).  Zero-length strings are always identical.  This behavior
     is not required by C and portable code should only depend on the sign of
     the returned value. */
#include "ft_printf.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*((char *)(s1 + i)) == *((char *)(s2 + i)) && i + 1 < n)
		i++;
	return (*((unsigned char *)(s1 + i)) - *((unsigned char *)(s2 + i)));
}

/*
1: I create a loop iterator called 'i' that I set to 0.

2: I make an if statement to the condition of 'n' being 0. if this is
true, that means there are no bytes to compare, and it will always
be equal. Equal is signified by 0, so I return 0. 

3: I start my whileloop to the conditions of s1[i] being equal to 
s2[i], and i + 1 being less than size_t n, which is the amount of
bytes we are supposed to compare.
<< why does "i + 1 < n" work, and "i <= n - 1" does not? >>

4: As soon as this is not the case, and one character in s1 is not 
equal to that iteration of s2, the whileloop breaks and I return
the sum of the difference. I subtract s2[i] from s1[i], and hereby
return the difference between the two. The answer will be positive
or negative, depending on the difference between the strings.

I typecast these values as unsigned chars, because when handling
raw binary data, signed types' behaviour is undefined. 

5: kthx.
*/