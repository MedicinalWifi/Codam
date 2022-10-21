/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp_U.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:38 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 12:30:34 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int memcmp(const void *s1, cons void *s2, size_t n)
{
    int i;
    i = 0;
    int cmp;
    cmp = 0;
    char* s1 = "String 1 was bigger.";
    char* s2 = "String 2 was bigger.";
    char* s1_2 = "The strings were the same.";
    while((unsigned char*)s1[i] != "\0" && (unsigned char*)s2[i] != "\0" && i <= len)
    {
       cmp += ((unsigned char*)s1[i]-(unsigned char*)s2[i]);
       i++;
    }

    if (cmp > 0)
    {
        return(1);
    }
    else if (cmp = 0)
    {
        return(0);
    }
    else if (cmp < 0)
    {
        return(-1);
    }
}