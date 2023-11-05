/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:33 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:42:34 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *str, int c, size_t n)
{
    unsigned char *ptr;

    ptr = (unsigned char *)str;
    while(n-- > 0 && ptr)
    {
        *ptr++ = c;
    }

    printf("memset = %s\n", ptr);
    return ptr;
}