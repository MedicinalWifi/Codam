/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:01:47 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 13:53:44 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_isascii(int c)
{
    if(c >= 0 && c <= 177)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
/*

1: i checked if the char has a ascii number inbetween 0 and 177, 
which includes all listed chars in the ascii table.

2: if it does, I return 1 for true.

3: if it does not, I return 0 for false.

4: kthx.
*/