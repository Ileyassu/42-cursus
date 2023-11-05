/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:28 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:42:29 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void * src, size_t n)
{
    const unsigned char *ptr;
    unsigned char *d;

    ptr = (const unsigned char *)src;
    d = (unsigned char *)dest;

    if(ptr && n > 0)
    {
        while(n-- > 0)
        {
            *d++ = *ptr++;
        }
        return ((char *)dest);
    }

    return (NULL);
}