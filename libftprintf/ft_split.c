/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 11:18:31 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
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
#include "ft_printf.h"

static size_t	ft_substr_len(char *s, char c, int str_i);
static char		**ft_writestring(char c, char *s, char **ans, int substr_c);
static char		*ft_substr_array(char *ans, char *s, int str_i, int len);
static char		**free_malloc_retroactively(char **ans, int ans_i);

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		i;
	int		substr_c;

	substr_c = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
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
				return (free_malloc_retroactively(ans, ans_i));
			ans[ans_i] = ft_substr_array(ans[ans_i], s, str_i, len);
			ans_i++;
			while (s[str_i] != c && s[str_i])
				str_i++;
		}
		while (s[str_i] == c && s[str_i])
			str_i++;
	}
	ans[ans_i] = 0;
	return (ans);
}

static size_t	ft_substr_len(char *s, char c, int str_i)
{
	int	substr_len;

	substr_len = 0;
	while (s[str_i] && s[str_i] != c)
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
	ans[i] = '\0';
	return (ans);
}

static char	**free_malloc_retroactively(char **ans, int ans_i)
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

/*
1: I start by prototyping all my functions so I know what's in my code.

2: I start by creating a placeholder for the answer array, a loop iterator, 
and a placeholder for the substring count. 

3: I create an if statement to the condition of the string being NULL,
in which case I return NULL. 

4: I first handle substring count. In order to do this, I create a 
whileloop to the condition of s not being terminated.

	4a: I nested a while loop that checks if the current iteration of
	s == the deliminator character. This would mean it's at the start,
	so I skip those. 

	4b: I create an if statement for s[i] not being terminated, and 
	s[i] not being a deliminator character. If that's true, I add 1
	to my substring count. 

	4c: I create another while loop to pass characters inside that
	substring. It breaks when it hits the end, or a deliminator 
	character. 

5: I then allocate memory to the answer array by using a double 
array typecasted version of the malloc function. I'm writing
the size of a char pointer at the count of substr + 1 for the 
'\0' string. I protect this. 

6: I redefine ans with my writestring function. 

	6a: I create a loop iterator for the answer string, for the 
	string iteration, and for the length of the substring. 

	6b: I start a whileloop to the condition of the string iteration
	being less than the total substring count. 

	6c: I create an if statement to the condition of s[str_i] not 
	being the deliminating character. 

	6d: I then define len with my substr_len function. 

		6d1: I create a placeholder for my substring length. 
		
		6d2: while s[str_i] is not terminated, and it is not
		the deliminating character, I count the places in 
		substr_len, and iterate through s with str_i. 

		6d3: I return the stringlength.

	6e: I allocate memory to the first string of the answer array. 
	I protect this. If this fails at any point, I use my 
	'free malloc retroactively' function, to delete all previous
	memory allocations as well.
		6e1: I create a while loop to the condition of the answer
		array being bigger than 0. I free all allocations. 

		6e2: I then free ans[0] and ans itself. I return NULL.
	
	6f: I write the string into the pointer by using substr_array.
		
		6f1: I create a loop iterator. 

		6f2: I create a whileloop to the condition of s[str_i] not
		being terminated, and i being less than the substr length, 
		specified in 6d. 

		6f3: I iterate through the answer array, filling it with 
		s[str_i]. I add '\0' to the final place in the array, 
		and return the result.
	
	6g: I iterate to the next answer array, and use a while loop to 
	run through the original string until the deliminating character
	is found. 
	
	6h: the if statement ends, and deliminating characters are 
	iterated through. This process repeats until all substrings 
	are written. 

	6i: The last string is the terminating string, and I set this 
	to '\0', after which I return the finished double array. 

7: If ans = NULL, which means allocation failed at some point, 
I return NULL. If it succeeded, it holds the double array which 
is I then return. 

8: kthx.
	
*/