/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:44 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:45:45 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    while (*str)
    {
        str++;
    }
    str--;
    while (*str--)
    {
        if (*str == c)
        {
            return (char *)str;
        }
    }
    return (NULL);
}