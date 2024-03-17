/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:13:05 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/12 12:40:20 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, int base, int uppercase)
{
	int		count;
	char	*b;

	count = 0;
	if (uppercase == 1)
		b = "0123456789ABCDEF";
	else
		b = "0123456789abcdef";
	if ((int)n < 0)
	{
		ft_putchar('-');
		count += ft_putnbr_base(-n, base, uppercase) + 1;
	}
	else if (n >= (unsigned int)base)
	{
		count = ft_putnbr_base(n / base, base, uppercase);
		count += ft_putchar(b[n % base]);
	}
	else
		count += ft_putchar(b[n]);
	return (count);
}
