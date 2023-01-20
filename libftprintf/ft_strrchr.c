/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 12:49:49 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string. */
#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		check;

	i = 0;
	check = -1;
	if ((char)c == '\0')
		return ((char *)s + (ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			check = i;
		}
		i++;
	}
	if (check >= 0)
		return ((char *)(s + check));
	else
		return (NULL);
}

/*

1: I create a loop iterator i, which I set to 0. I also create a 
check switch, that i set to -1. 

2: I make an if statement to the condition of c being '\0', in
which case the last occurance will always be the final char of 
the string. I use strlen to figure out the correct iteration
of the string 's' to create a pointer to the final char.

3: I open a while loop to the condition of s[i] not yet having
reached termination.

4: I make an if statement to the condition of s[i] being equal
to the contents of 'c', typecasted as a char. 

We use an int to store the ascii value, because some chars that
need to be searched aren't easily defined using a keyboard. if 
the searched char is 'del', or other nonprint, it is easier to 
use int for ascii value, and later convert to char.

If the if statement is true, I save 'i' in the 'check' variable
i have created. every time this statement is true, check
gets updated to the latest 'i' value for discovery of c. 

5: After this while loop has gone through the complete string, 
there is another if statement. If 'check' is more than 0, this
means that it has been activated at some point. i started at 
0, and check at -1, so check being higher or equal to 0
tells that a discovery has happened. 

if it did, I return a pointer at the location of s + check, 
check being the iteration of i that discovered the latest
c.

6: Else, I return 'NULL' because the search returned empty 
handed. 

7: kthx.
*/