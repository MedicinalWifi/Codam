/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:05:52 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 13:43:41 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* 
1: i checked if the char has an ascii
number in the range of printable chars. 

2: if it does, i am returning 1 for true.

3: if not, then I return 0 for false.

4: kthx.
*/