/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 13:56:02 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/19 14:54:19 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_string(char *data, int *str_ln)
{
	char	*s;

	if (data == NULL)
	{
		*str_ln += 6;	
		write(1, "(null)", 6);
		return ;
	}
	s = ft_calloc(2000, sizeof(char));
	if (!s)
		return ;
	
	ft_memcpy((void *)s, (const void *)data, ft_strlen((const char *)data));
	*str_ln += ft_strlen(s);
	write(1, s, ft_strlen(s));
	free(s);
	return ;
}