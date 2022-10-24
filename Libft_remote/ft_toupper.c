/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:00:23 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 12:10:42 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	else
	{
		return (c);
	}
}

/*
ft_toupper: We're trying to convert lowercase chars to uppercase.

1: i checked if the char's ascii number is 
in the range of lowercase alpha chars. 

2: if it is, i am converting it to upper 
range by subtracting 32 places to it in the 
ascii table. 

3: if it is not a lower case char, 
i do nothing and return the char unchanged.

4: kthx.
*/