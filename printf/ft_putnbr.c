/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:25:19 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/30 17:25:20 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_dakchi(int nb)
{
	int	digits;

	digits = 0;
	if (nb <= 0)
		digits++;
	while (nb)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

int	ft_putnbr(int n)
{
	long long	nbr;
	int			count;

	count = 0;
	count = count_dakchi(n);
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	return (count);
}
