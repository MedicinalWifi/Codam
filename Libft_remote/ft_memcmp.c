/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:26:38 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/21 15:05:45 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int memcmp(const void *s1, const void *s2, size_t n)
{
    int i;
    i = 0;
    int cmp;
    cmp = 0;

    while((unsigned char*)s1[i] != "\0" && (unsigned char*)s2[i] != "\0" && i <= len)
    {
       cmp += ((unsigned char*)s1[i]-(unsigned char*)s2[i]);
       i++;
    }

    if (cmp > 0)
    {
        return(1);
    }
    else if (cmp == 0)
    {
        return(0);
    }
    else if (cmp < 0)
    {
        return(-1);
    }
}