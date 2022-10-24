/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:51:32 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 13:45:00 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90 && c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*

1: i checked if the char has an ascii number in the range of alpha chars. 

2: if it does, i'm returning a 1 value for true.

3: if it does not, I'm returning 0 for false.

4: kthx.
*/