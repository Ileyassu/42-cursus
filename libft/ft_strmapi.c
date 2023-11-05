/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:43:50 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:43:51 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    if(!s)
        return (NULL);
    char *ptr;
    int length;
    int i;
    char *func;

    i = 0;
    length = ft_strlen(s);
    ptr = (char *)malloc(sizeof(char) * (length + 1));

    while(s[i])
    {
        ptr[i] = f(i, s[i]);
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}