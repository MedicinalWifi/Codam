/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:55:05 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/20 13:26:34 by lhop          ########   odam.nl         */
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
/* 
1: i checked if the char has an ascii number in the range of digits. 

2: if it does, i am returning a 1 for true.

3: If not, I am returning 0 for false.

4: kthx.
*/