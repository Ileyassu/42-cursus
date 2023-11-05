/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:03 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:46:04 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char *s, unsigned int pos, size_t size)
{

    if (s == NULL)
        return (NULL);

    char *ptr;
    char *strpos;

    size_t str_len = ft_strlen(s);
    if (pos > str_len || size == 0)
        return (NULL);
    
    pos--;
    strpos = (s + pos);
    
    ptr = (char *)malloc(size + 1);
    if(ptr == NULL)
        return NULL;

    char *res = ptr;
    
    while((size > 0) && (*(s + pos) != '\0'))
    {
        *ptr++ = *(s + pos++);
        size--;
    }
    *ptr = '\0';
    return(res);
}