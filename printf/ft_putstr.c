/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:28:12 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/28 00:55:33 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *s)
{
    if(s == NULL)
    {
        write(1, "(null)", 7);
        return (0);
    }
    int i;
    int count;
    
    i = 0;
    count = ft_strlen(s);
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (count);
}
