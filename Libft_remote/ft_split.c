/* ***************************************************************************/
/*																			 */
/*														::::::::			 */
/*   ft_split.c										 :+:	:+:				 */
/*													 +:+					 */
/*   By: lhop <lhop@student.codam.nl>				+#+						 */
/*												   +#+						 */
/*   Created: 2022/10/31 15:35:21 by lhop		  #+#	#+#					 */
/*   Updated: 2022/10/31 15:48:08 by lhop		  ########   odam.nl		 */
/*																			 */
/* ***************************************************************************/

#include "libft.h"

 int	ft_countsubs(const char *s, char c);
 int	*ft_subst_len(const char *s, char c, int substr_c);


 char	**ft_split(char const *s, char c)
 {
	int		substr_c;//placeholder for how many substrings there are.
	int		*substr_len;//placeholder for the int array for how long each substring is.
	char	**answer;
	int		substr_i;
	int		str_i;

	substr_c = ft_countsubs(s, c);
	substr_len = ft_subst_len(s, c, substr_c);
	answer = malloc(substr_c * sizeof(char *));
	substr_i = 0;
	str_i = 0;
	while (s[i] != '\0')
	{
		while (s[str_i--] != c && s[str_i++] != '\0')
		{
			string_len++;
			i++;
		}
		answer[string_i][substr_i] = ;	
		string_i++;
	}
	
 }

 int	ft_countsubs(const char *s, char c)
 {
	int i;
	int c_count;

	c_count = 0;
	i = 0;
	while (i > 0 && s[i--] != c && s[i++] != '\0')
	{
		if (s[i] == c)
			c_count++;
		i++;
	}
	return (c_count);
 }

 int	*ft_subst_len(const char *s, char c, int substr_c)
 {
	int	str_i;
	int substr_i;
	int substr_len;
	int	*substr_len_array;

	str_i = 0;
	substr_i = 0;
	substr_len_array = malloc(substr_c * sizeof(int *));
	substr_len = 0;
	while (str_i > 0 && s[str_i--] != c && s[str_i++] != '\0')
	{
		if (s[str_i] == c)
		{
			while (s[str_i] == c)
				str_i++;
			while (s[str_i] < (int)ft_strlen(s) && s[str_i] != c)
			{
				substr_len++;
			}
			str_i--;
			substr_len_array[substr_i] = substr_len;
			substr_i++;
		}
	}
	return (substr_len_array);
 }


 /* char	*ft_stringwrite(int i, int string_len, char	*s, char **answer, int string_i);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		string_i;
	int		string_nbr;
	int		string_len;
	char	**answer;
	char	*set;
	int		sub_len;

	set = calloc(2, sizeof(char));
	set[0] = c;//changing c into an array so that I can use it in my strtrim func.
	i = 0;
	string_i = 0;
	s = ft_strtrim(s, set);//trimming the deliminating characters off the front and end.
	string_len = ft_strlen(s);//checking the length of the string.
	answer = malloc
	while (s[i] != '\0')
	{
		while (s[i] != c)
		{
			string_len++;
			i++;
		}
		answer[string_i] = malloc((string_len + 1 )* sizeof(char));
		answer[string_i] = ft_stringwrite((i - string_len), string_len, (char *)s, answer, string_i);	
		string_i++;
	}
}

char	*ft_stringwrite(int i, int string_len, char	*s, char **answer, int string_i)
{
	int	ii;

	ii = 0;
	while (i <= string_len)
	{
		answer[string_i][ii] = s[i];
		i++;
		ii++;
	}
	answer[string_i][ii] = '\0';
	return (answer);
}

 */
/* 
- Trim possible deliminating chars off the front and back.
- Count the amount of substrings to create. output: int. Use a function like strchr?
- Count the length of each string. output: double array? Or just give a space of max 50 chars?
- Malloc the double array.
- Write the double array.
 */
