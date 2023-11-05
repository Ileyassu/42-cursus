/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:24 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:42:25 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;
    int i = 0;

    if(s1 == NULL || s2 == NULL || n <= 0)
    {
        return (0);
    }
    while (n > 0 && *s1 == *s2)
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}