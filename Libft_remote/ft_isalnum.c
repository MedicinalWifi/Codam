/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:59:02 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/24 13:46:39 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	alphacheck;
	int	digitcheck;

	alphacheck = ft_isalpha(c);
	digitcheck = ft_isdigit(c);
	if (alphacheck == 1 && digitcheck == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* 

1: i used two previous functions to check for 
alpha chars, and then for digit chars. 

2: if coutcome of those are both true, 
this superfunction is also true, so I return 1.

3: if the outcome for 1 or more is false, I return 0 for false.

4: kthx.
*/