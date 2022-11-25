/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:38 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/25 13:41:58 by lhop          ########   odam.nl         */
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
#include "libft.h"

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

*/