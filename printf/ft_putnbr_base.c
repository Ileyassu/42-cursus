/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:13:05 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/27 12:49:27 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putnbr_base(long nbr, char *base)
{
    int len;
    char c;
    int count;
    
    len = ft_strlen(base);
    count = count_digits(nbr);
    if(nbr < 0)
    {
        nbr *= -1;
        ft_putchar('-');
    }
    if(nbr < len)
    {
        c = base[nbr];
        count++;
        ft_putchar(c);
    }
    else
    {
        ft_putnbr_base(nbr / len, base);
        ft_putnbr_base(nbr % len, base);
    }
    //printf("%d\n", count);
    return (count);
}

int hexabase(int nbr)
{
    int count = 0;
    count = ft_putnbr_base(nbr, "0123456789abcdef");
    return (count);
}
int ultra_hexabase(int nbr)
{
    int count = ft_putnbr_base(nbr, "0123456789ABCDEF");
    return (count);
}