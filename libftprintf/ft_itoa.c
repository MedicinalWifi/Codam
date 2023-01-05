/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:35:03 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/05 12:29:39 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Function name ft_itoa
Prototype 				char *ft_itoa(int n);
Turn in files			-
Parameters 				n: the integer to convert.
Return value 			The string representing the integer.
						NULL if the allocation fails.
External functs. 		malloc
Description 			Allocates (with malloc(3)) and returns a string
						representing the integer received as an argument.
						Negative numbers must be handled. */
#include "libftprintf.h"

char			*ft_itoa(int n);
static int		ft_nbr_len(long n);

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

/* int main(void)
{
	long long a = 0;
	printf("My itoa: %s\n", ft_itoa(a));
	a = -2147483648LL;
	printf("My itoa: %s\n", ft_itoa(a));
	a = -623;
    printf("My itoa: %s\n", ft_itoa(a));
	a = 156;
	printf("My itoa: %s\n", ft_itoa(a));
	return(0);

	1: First I create char pointer 'result' for the char array that holds
	the result. I create size_t 'nbr_len' for the number length, 
	and create long 'num' to convert int n into a long int to safely handle
	edge case numbers.
	
	2: I define nbr_len with my nbr_len function. 

		2a: I create size_t 'i', and set it to 0. 

		2b: I create an if statement for the number being 0, in which case 
		I return 1. 

		2c: I create an if statement for the number being less than 0, in 
		which case I increase i to make place for the - sign, and multiply 
		the number by -1 to make it positive. 

		2d: I create a while loop to the condition of the number being 
		above 0. In this loop, I keep dividing the number by 10 and increasing 
		i every time I succesfully do so. As soon as it is 0, I will have 
		covered all powers of 10, which means all places of the number will 
		have been counted. I return 'i'. 
		
	3: I allocate memory to 'result' with malloc, by using nbr_len + 1 for 
	'\0'. I protect this allocation.

	4: I create an if statement to the condition of num being less than 0, 
	in which case I redefine the number into its positive counterpart, 
	and put the '-' sign at the first iteration of result, at 'result[0]'.

	5: I then null terminate the end of result, because I will alter 
	nbr_len later, so I have to use the correct value now.

	6: I create an if statement to the condition of num being 0, in which
	case i set 'result[0]' to 0. I do this because my while loop doesn't 
	handle 0. 

	7: subtract 1 from nbr_len, because I want to use this as a loop 
	iterator, so I will cut out the terminating character so that it 
	starts at the end of the to be created string.
	
	8: I set a whileloop to the condition of num being higher than 0, 
	and nbr_len being higher or equal to 0. 
	
		8a: I then write the number into the result, starting at the last 
		place. I do this by calculating the num's modular from 10, ending 
		up with the last digit. I then add this number to char '0', which 
		leaves me with the ascii value of a char corresponding to the int. 
		
		8b: I then divide the number by 10, to move to the next value place
		in the number. The num's modular from 10 is now the next digit to 
		the left.  
		
		8c: I decrease nbr_len by 1, so that I can write into the next place
		to the left with the num's new modular from 10. 

		8d: This loop repeats until it breaks at 0. I will have written all 
		numbers into the placeholder. 

	9: I return my result. 

	10: kthx.
} */