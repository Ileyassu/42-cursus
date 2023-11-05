/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:20 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:42:21 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr =  (const unsigned char *)s;
    unsigned char *m = (unsigned char *)&c;

    if(n < 0 || *ptr == '\0')
    {
        return NULL;
    }
    while(n > 0)
    {
        if (*ptr == *m)
        {
            return (void *)ptr;
        }
        ptr++;
        n--;
    }
    return (NULL);
}