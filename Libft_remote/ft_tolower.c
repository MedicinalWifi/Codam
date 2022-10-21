/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:43:06 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 15:00:56 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c)
{
    if(c >= 65 && c <= 90)
    {
        return(c + 32);
    }
    else
    {
        return(c);
    }
}
/*
ft_tolower: We're trying to convert uppercase chars to lowercase.

1: i checked if the char's ascii number is 
in the range of uppercase alpha chars. 

2: if it is, i am converting it to lower 
range by adding 32 places to it in the 
ascii table. 

3: if it is not an upper case char, 
i do nothing and return the char unchanged.

4: kthx.
*/