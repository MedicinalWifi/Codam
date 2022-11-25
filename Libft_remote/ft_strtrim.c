/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 11:00:33 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/22 11:04:01 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* 	Function name ft_strtrim
	Prototype 			char *ft_strtrim(char const *s1, char const *set);
	Turn in files 		-
	Parameters 			s1: The string to be trimmed.
						set: The reference set of characters to trim.
	Return value 		The trimmed string.
						NULL if the allocation fails.
	External functs. 	malloc
	Description 		Allocates (with malloc(3)) and returns a copy of
						’s1’ with the characters specified in ’set’ removed
						from the beginning and the end of the string. */
#include "libft.h"

static	int	ft_checkset1(char *s1, char *set, int setlen, int strlen)
{
	int		i;
	int		si;

	si = 0;
	i = 0;
	while (si < setlen && i < strlen)
	{
		if (set[si] == s1[i])
		{
			i++;
			si = -1;
		}
		si++;
	}
	return (i);
}

static int	ft_checkset2(char *s1, char *set, int setlen, int strlen)
{
	int		i;
	int		si;
	int		check;

	si = 0;
	i = strlen - 1;
	check = 0;
	while (si < setlen && i >= 0)
	{
		if (set[si] == s1[i])
		{
			i--;
			check++;
			si = -1;
		}
		si++;
	}
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		setlen;
	int		st;
	int		end;
	char	*newstring;
	int		i;

	i = 0;
	setlen = ft_strlen(set);
	st = ft_checkset1((char *)s1, (char *)set, setlen, (int)ft_strlen(s1));
	end = ft_checkset2((char *)s1, (char *)set, setlen, ft_strlen(s1));
	if (st == (int)ft_strlen(s1))
	{
		newstring = ft_calloc(1, sizeof(char));
		return (newstring);
	}
	newstring = malloc((((int)ft_strlen(s1) + 1) - (st + end)) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i <= ((((int)ft_strlen(s1) - 1) - st) - end))
	{
		newstring[i] = (char)s1[i + st];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
