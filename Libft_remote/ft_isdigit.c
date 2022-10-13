/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:55:05 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/11 11:58:36 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c)
{
    if(c >= 48 && c <= 57)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
/* i checked if the char has an ascii
number in the range of digits. if it does, 
i am returning a 1 for true.*/