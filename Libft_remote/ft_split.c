/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 11:18:31 by lhop          #+#    #+#                 */
/*   Updated: 2022/11/25 12:14:13 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_split
Prototype 				char **ft_split(char const *s, char c);
Turn in files 			-
Parameters 				s: The string to be split.
						c: The delimiter character.
Return value 			The array of new strings resulting from the split.
						NULL if the allocation fails.
External functs. 		malloc, free
Description 			Allocates (with malloc(3)) and returns an array
						of strings obtained by splitting ’s’ using the
						character ’c’ as a delimiter. The array must end
						with a NULL pointer. */
#include "libft.h"

static size_t	ft_substr_len(char *s, char c, int str_i);
static char		**ft_writestring(char c, char *s, char **ans, int substr_c);
static char		*ft_substr_array(char *ans, char *s, int str_i, int len);
static char		**free_malloc_recursively(char **ans, int ans_i);

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		substr_c;

	substr_c = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			substr_c++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	ans = (char **)malloc(sizeof(char *) * (substr_c + 1));
	if (!ans)
		return (NULL);
	ans = ft_writestring(c, (char *)s, ans, substr_c);
	return (ans);
}

static char	**ft_writestring(char c, char *s, char **ans, int substr_c)
{
	int		str_i;
	int		ans_i;
	int		len;

	str_i = 0;
	ans_i = 0;
	len = 0;
	while (ans_i < substr_c)
	{
		if (s[str_i] != c)
		{
			len = ft_substr_len(s, c, str_i);
			ans[ans_i] = (char *)malloc((len + 1) * sizeof(char));
			if (!ans[ans_i])
				return (free_malloc_recursively(ans, ans_i));
			ans[ans_i] = ft_substr_array(ans[ans_i], s, str_i, len);
			ans_i++;
			while (s[str_i] != c && s[str_i] != '\0')
				str_i++;
		}
		while (s[str_i] == c && s[str_i] != '\0')
			str_i++;
	}
	ans[ans_i] = 0;
	return (ans);
}

static size_t	ft_substr_len(char *s, char c, int str_i)
{
	int	substr_len;

	substr_len = 0;
	while (s[str_i] != '\0' && s[str_i] != c)
	{
		substr_len++;
		str_i++;
	}
	return (substr_len);
}

static char	*ft_substr_array(char *ans, char *s, int str_i, int len)
{
	int	i;

	i = 0;
	while (s[str_i] && i < len)
	{
		ans[i] = s[str_i];
		i++;
		str_i++;
	}
	ans[i] = 0;
	return (ans);
}

static char	**free_malloc_recursively(char **ans, int ans_i)
{
	while (ans_i > 0)
	{
		free(ans[ans_i]);
		ans_i--;
	}
	free(ans[0]);
	free(ans);
	return (NULL);
}
