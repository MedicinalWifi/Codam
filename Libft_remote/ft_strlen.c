/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:08:45 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/11 13:32:20 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *string)
{
    int i;
    i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return(i);
}
/* i created an index, to cycle through
the string by using a while loop, which 
will keep applying the operation within as 
long as the \0 characte has not been reached.
As i do this, i am increasing the size of my
index by 1, every time another place 
has been found that is not \0. 
i then return the size of my index, which
tells you how long the string was.*/