/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:45:42 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, int len)
{
    const char *ptr;

    while(*big++ && --len > 0)
    {
        ptr = little;
        while(*big++ == *ptr++ && --len > 0)
        {
            if(*ptr == '\0')
            {
                return (char *)big;
            }
        }
    }
    return NULL;
}