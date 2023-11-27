/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printaddress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:19 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/27 00:12:20 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printaddress(unsigned long *n)
{
    unsigned long nbr = (unsigned long)n;
    char address[20];
    char *base;
    int size;
    int count;

    count = 0;
    base = "0123456789abcdef";
    size = sizeof(address);
    address[size] = '\0';
    size--;
    while(nbr > 0)
    {
        address[size] = base[nbr % 16];
        nbr /= 16;
        size--;
        count++;
    }
    write(1, "0x", 2);
    write(1, address, sizeof(address));
    return (count);
}