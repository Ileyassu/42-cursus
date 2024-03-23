/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_unsigned_thing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:28:45 by ilyas             #+#    #+#             */
/*   Updated: 2023/12/02 19:05:28 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_putnbr(unsigned int nbr)
{
	int	count;

	count = count_digits(nbr);
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		unsigned_putnbr(nbr / 10);
		unsigned_putnbr(nbr % 10);
	}
	return (count);
}
