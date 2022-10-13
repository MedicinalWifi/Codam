/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:05:52 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/11 13:08:27 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int c)
{
    if(c >= 32 && <= 126)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
/* i checked if the char has an ascii
number in the range of printable chars. 
if it does, i am returning 1 for true.*/