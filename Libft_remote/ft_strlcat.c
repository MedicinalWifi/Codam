/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhop <lhop@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:34:33 by lhop          #+#    #+#                 */
/*   Updated: 2022/10/18 12:49:56 by lhop          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_strlcat(*src, *dst)
{
    int src_len;
    src_len = ft_strlen(*src);

    int dst_len:
    dst_len = ft_strlen(*dst);

    int i;
    i = src_len + dst_len;

    int write_i;
    write_i = 0;

    int src_i;
    src_i = 0;

    char strlcat[i];
    while (write_i <= dest_len)
    {
        strlcat[write_i] = dst[write_i];
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