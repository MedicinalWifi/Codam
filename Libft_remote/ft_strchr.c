/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 12:06:13 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 13:37:30 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *book, int letter)
{
	int	i;
	int	book_len;

	i = 0;
	book_len = ft_strlen ((char *)book);
	while (i < book_len + 1)
	{
		if (book[i] == letter)
		{
			return ((char *)(book + i));
		}
		i++;
	}
	return (NULL);
}
/* 
1: I set an index to cycle through the source(book)

2: I create another index, to find out the source length.
I do this so that i know when to stop searching.

3: I create a while loop on the condition that i is less than book_len +1.
I add the plus 1 so that the terminating character is included.

4: I open an 'if' function on the condition that the current place in the book
is the same as the letter to be searched. 

5: if it is, I return that place in the book. 
Not sure why return((char*)(book + i)) works, 
and return((char*)(book[i])) does not.

6: If the letter is not found, 'NULL' is returned.

7: kthx
*/