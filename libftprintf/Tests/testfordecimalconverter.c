#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char 		*ft_floattostring(float f);
int 		ft_countnumsize(float f);
char 		*ft_multiplyfloat(float f, char *postdecimal, int numsize);
char		*ft_itoa(int n);
static int	ft_nbr_len(long n);

char *ft_floattostring(float f)
{
    char        *whole;
    char        *predecimal;
    char        *postdecimal;
    int         i;
    int         numsize;
    
    numsize = ft_countnumsize(f);
    predecimal = malloc(strlen(ft_itoa(f)) * sizeof(char));
    postdecimal = calloc(6, sizeof(char));
    whole = calloc((strlen(ft_itoa(f)) + 7), sizeof(char));
    if (!predecimal || !postdecimal || !whole)
        return(NULL);
    predecimal = ft_itoa(f);
	printf("predecimal: %s\n", predecimal);
    postdecimal = ft_multiplyfloat(f, postdecimal, numsize);
	printf("postdecimal: %s\n", postdecimal);
	strlcat(whole, predecimal, (size_t)numsize + 1);
	strlcat(whole, postdecimal, (size_t)numsize + 7);
    return(whole);
}

int ft_countnumsize(float f)
{
    int numsize;
    numsize = 0;
	int i;
	i = f;
    
    while (i > 0)
    {
    	i = i / 10;
        numsize++;
    }
	printf("numsize: %i\n", numsize);
    return(numsize);
}

char *ft_multiplyfloat(float f, char *postdecimal, int numsize)
{
    char *wholenumber;
    int wholenumbersize;
    int    pd_i;
    int    wn_i;
    
    pd_i = 1;
    wn_i = numsize;
    wholenumber = calloc(20, sizeof(char));
    f = f * 10000;
    wholenumber = ft_itoa(f);
    wholenumbersize = strlen(wholenumber);
    
    postdecimal[0] = '.';
    while (wholenumber != '\0' && pd_i <= 5)
    {
        postdecimal[pd_i] = wholenumber[wn_i];
        pd_i++;
        wn_i++;
    }
    return(postdecimal);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			nbr_len;
	long			num;

	num = n;
	nbr_len = ft_nbr_len(num);
	result = malloc((nbr_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		num = (num * -1);
		result[0] = '-';
	}
	result[nbr_len] = '\0';
	if (num == 0)
		result[0] = '0';
	nbr_len -= 1;
	while (num > 0 && nbr_len >= 0)
	{
		result[nbr_len] = ((num % 10) + '0');
		num = num / 10;
		nbr_len--;
	}
	return (result);
}

static int	ft_nbr_len(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n <= 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int main(void)
{
  float f;
  char *s;
  
  s = malloc(20 * sizeof(char));
  f = 1231.42;
  
  s = ft_floattostring(f);
  printf("Here is my float printed as a string: %s\n", s);
  return(0);
}