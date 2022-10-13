/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:51:32 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/11 11:54:49 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
    if(c >= 65 && c <= 90 && c >= 97 && c <= 122)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
/*i checked if the char has an ascii number 
in the range of alpha chars. if it does, 
i'm returning a 1 value for true.*/