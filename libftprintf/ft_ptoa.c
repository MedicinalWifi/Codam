/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ptoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 14:38:30 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 14:43:32 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_ptoa(void *p)
{
	unsigned long p_copy;
	char *str;

	unsigned long p_copy = (unsigned long)p;
	str = malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	
}