/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:12 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:45:33 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if(!s1 || !s2)
    {
        return (NULL);
    }   
    i = 0;
    while(s1[i] && s1[i] == s2[i] && i < n)
    {
        i++;
    }
    return (s1[i] - s2[i]);
}