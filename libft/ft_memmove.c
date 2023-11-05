/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:30 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:49:22 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    if(d == NULL && s == NULL)
        return (NULL);

    if((s > d) || (d > s + n))
    {
        ft_memcpy(d, s, n);
    }
    else
    {
        while(n > 0 && s)
        {
            d[n] = s[n];
            n--;
        }
    }
    return (dest);
}