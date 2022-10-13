/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:43:06 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/11 11:51:16 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_tolower(int c)
{
    if(c >= 65 && <= 90)
    {
        return(c + 32);
    }
    else
    {
        return(c);
    }
}
/*i checked if the char's ascii number is 
in the range of uppercase alpha chars. 
if it is, i am converting it to lower 
range by adding 32 places to it in the 
ascii table. if it is not an uppercase char, 
i do nothing. */