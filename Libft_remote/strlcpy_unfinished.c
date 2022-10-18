/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlcpy_unfinished.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:56:13 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/18 15:22:43 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t strlcpy(char *dst, char *src, size_t size)
{
   int src_len;
    src_len = ft_strlen(*src);

    int dst_len:
    dst_len = ft_strlen(*dst);

    int src_i;
    src_i = 0;

    dst_len++;
    while (src_i <= size)
    {
        dst[dst_len] = dst[write_i];
        write_i++;
    }
    while (write_i <= i)
    {
        strlcat[write_i] = src[src_i];
        write_i++;
        src_i++;
    }
    strlcat[write_i] = "\0";
    return(strlcat); 
}