/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:25 by lhop          #+#    #+#                 */
/*   Updated: 2023/01/09 14:13:48 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* int atoi(const char *str);
 DESCRIPTION
     The atoi() function converts the initial portion of the string pointed to
     by str to int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

     While the atoi() function uses the current locale, the atoi_l() function
     may be passed a locale directly. See xlocale(3) for more information.
	  */
#include "ft_printf.h"

static int	ft_checkspace(const char *str);
static int	ft_checkplusminus(const char *str, int i);
static int	ft_makenum(const char *str, int numstart, int posneg);

int	ft_atoi(const char *str)
{
	int	i;
	int	posneg;
	int	num;

	i = ft_checkspace(str);
	posneg = ft_checkplusminus(str, i);
	if (!str || posneg < -1)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
	{
		num = ft_makenum(str, i, posneg);
		return (num);
	}
	else
	{
		return (0);
	}
}

static int	ft_makenum(const char *str, int i, int posneg)
{
	int	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * posneg);
}

static int	ft_checkplusminus(const char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+' || str[i] >= '0' || str[i] <= '9')
		return (1);
	else
		return (-2);
}

static int	ft_checkspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

/* int	main(void)
{
	int	num;

	num = ft_atoi("    -29873343adlskja");
	printf("The converted integer is %i.\n", num);
	return (0);
}

 1: First I create prototypes at the top of my code. I know this
 isn't necessary if I were to move my main function underneath
 the helpers, but I like being able to quickly see what functions
 my code contains. 

 2: I start my atoi by declaring 3 vars, loop iterator 'i', 
 placeholder 'posneg' for positive or negative sign, and 
 placeholder 'num' for the answer number. That would be the 
 int converted from the char string. 

 3: 'i' becomes redefined by my 'checkspace' function. 
 	3a: I make a loop iterator called 'i', set to 0. 

	3b: I create a while loop set to the condition of str[i] 
	having any type of possible white space. 

	3c: I iterate through the whitespace, and return the
	iteration of 'i', so it is now in the position where
	whitespace is skipped.

4: 'posneg' becomes redefined by my 'checkplusminus' function.
	4a: I create 2 if statements. One for if thre is a negative
	sign, in which case i return '-1'. Another for if there is 
	a positive sign, or it being a number straight away, in 
	which case I return 1 for positive. 
	
	4b: if there is another type of content, i return '-2', 
	which means the conversion will fail.

5: I create an if statement to the condition of str being empty, 
and posneg being < -1. In both of those cases it means that 
the conversion can't continue, and I return '0'.

6: I create an if statement to the condition of str[i] containing
a sign. if it does, i iterate over it. 

7: I create a final if statement to the condition of str[i] being 
a number. I then set 'num' to the value of my makenum function, 
to which I pass str, i, and posneg. 
	7a: i create a placeholder for the number, and set it to 0. 

	7b: I start a whileloop to the condition of str[i] being 
	a number. 

	7c: I redefine my number set to 0 by multiplying it by 10, 
	and adding the value of str[i]'s ascii value, minus the 
	value of 0 in the ascii table, leaving the actual int 
	representation of the number. The reason I multiply by 10
	is because the current number will be 1 power of 10 larger
	than the next number, because that is how counting 
	past 10 works. As long as there are more numbers, the previous
	ones will get another power of 10. 

	7d: When the string no longer contains numbers, the while
	loop breaks and I return the number multiplied by posneg. 
	if posneg was positive, it is x1, this does nothing. 
	if posneg was negative, it is x-1, which makes it negative.

8: I return the number I created. If, however, there was no number
contained in the string after whitespaces and signs were handled, 
i return '0'. 

9: kthx.
 */