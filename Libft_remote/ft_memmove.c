/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:43 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/24 13:47:47 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* void *memmove(void *dst, const void *src, size_t len);

DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.

RETURN VALUES
     The memmove() function returns the original value of dst. */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			*((char *)(dst + (len - 1))) = *((char *)(src + (len - 1)));
			len--;
		}
		return ((void *)dst);
	}
	while (dst < src && i < len)
	{
		*((char *)(dst + i)) = *((char *)(src + i));
		i++;
	}
	return ((void *)dst);
}

/* 
1: I create a loop iterator, and set it to 0.

2: I check for memory position of both variables 'dst' and 'src'. 

if dst is at a higher memory location than src, i want to copy to it
by starting from src at the end, and iterating to the front. 
Because we are copying a set amount of bytes, for example 5, overlap can 
never occur if dst is written to from back to front. 
overlap:

the letters represent memory location. D = destination, S = source.
  [a][b][c][d][e][f][g][h]
D:[ ][ ][ ][ ]
S:		[h][e][y][0]
In this case, destination has a lower memory address than source. 
destination[0] starts at a, and source[0] starts at c. 
if you were to copy from source to destintion starting from S[0] - D[0], 
you would never write the source into itself. The overwrite will 
always be 2 characters behind the currently written character. 
at point 'y' of S, it would write over 'h' of S, but that is no longer
needed and already written into dst. 
If you were to write into dest from back to front, you would immediately
write the '0' character into the next point of src. 'e' of src would have 
turned into 0. By the time we need to copy e, we are copying the end of
src again.

  [a][b][c][d][e][f][g][h]
D:		[ ][ ][ ][ ]
S:[h][e][y][0]
In this case, destination hs a higher memory address than source. 
it starts at c, and source starts at a. 
If you copy source into destination from 0 upwards, writing h into 
memory spot c will ater the source's 'y'. 
however, if you start write into destination from the end backwards, 
the overwrite will always be 2 spots behind, and does not affect
the writing process.

3: In the first loop, the case of destination being at a higher address 
than the source, copy the memory contents backwards. I typecast the void
pointers as char pointers, and refer to the adress position + len (the amount
to copy), minus one to exclude the null character. 

4: in the second loop, the case of destination being at a lower address
than the source, I copy the contents forwards. I typecast the void pointers
as char pointers, and refer to the address position + i, the iteration of 
the loop, which stops at 1 lower than 'len', which is when the required amount 
has been copied, but the null terminator left intact. if I were to do the 
complete len, i would copy the nul terminator but that is unnecessary.
*/
