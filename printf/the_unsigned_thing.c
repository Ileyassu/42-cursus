/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_unsigned_thing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:28:45 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/27 20:28:51 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int unsigned_putnbr(unsigned int nbr)
{
    int count; 
    
    count = count_digits(nbr);
    if(nbr <= 9)
        ft_putchar(nbr + '0');
    else
    {
        unsigned_putnbr(nbr / 10);
        unsigned_putnbr(nbr % 10);
    }
    return (count);
}