/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 11:06:22 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/12 12:27:51 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_char(char data, int *str_ln)
{
	char	c;

	c = (char)data;
	*str_ln += 1;
	write(1, &c, 1);
	return ;
}
