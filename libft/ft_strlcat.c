/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:43:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:43:42 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlcat(char *dest, const char *src, size_t size)
{
    int destlen;
    int srclen;
    int result;

    destlen = ft_strlen(dest);
    srclen = ft_strlen(src);
    if(destlen > size)
    {
        return size + srclen;
    }
    result = destlen + srclen;
    if (srclen < size - destlen)
	{
		ft_memcpy(dest + destlen, src, srclen);
		dest[destlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dest + destlen, src, size - destlen - 1);
		dest[size - 1] = '\0';
	}
	return (result);
}