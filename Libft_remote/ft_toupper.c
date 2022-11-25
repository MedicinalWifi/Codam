/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:00:23 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/24 14:05:09 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
     The toupper() function converts a lower-case letter to the corresponding
     upper-case letter.  The argument must be representable as an unsigned
     char or the value of EOF.

     Although the toupper() function uses the current locale, the toupper_l()
     function may be passed a locale directly. See xlocale(3) for more infor-
     mation.

RETURN VALUES
     If the argument is a lower-case letter, the toupper() function returns
     the corresponding upper-case letter if there is one; otherwise, the argu-
     ment is returned unchanged. */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

/*
ft_toupper: We're trying to convert lowercase chars to uppercase.

1: i checked if the char's ascii number is 
in the range of lowercase alpha chars. 

2: if it is, i am converting it to upper 
range by subtracting 32, which moves it 32 places back.

3: if it is not a lower case char, 
i do nothing and return the char unchanged.

4: kthx.
*/