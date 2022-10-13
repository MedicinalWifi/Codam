/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:59:02 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/11 11:59:02 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
int isalnum(int c)
{
   int alphacheck;
   int digitcheck;

   alphacheck = ft_isalpha(c);
   digitcheck = ft_isdigit(c);

   if(alphacheck == 1 && digitcheck == 1)
   {
        return(1);
   }
   else
   {
        return(0);
   }
}
/* i used two previous functions to check for 
alpha chars, and then for digit chars. 
if coutcome of those are both true, 
this superfunction is also true.*/