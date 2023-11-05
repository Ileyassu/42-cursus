/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:43:38 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:43:39 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int strings_length;
    char *ptr;
    char *result;

    strings_length = ft_strlen(s1) + ft_strlen((char *)s2);
    ptr = (char *)malloc(strings_length + 1);

    if (ptr == NULL)
        return (NULL);
    result = ptr;

    ft_memcpy(ptr, (char *)s1, ft_strlen(s1));
    ft_strlcat(ptr, s2, strings_length + 1);
    *(ptr + strings_length + 1) = '\0';

    return (result);
}