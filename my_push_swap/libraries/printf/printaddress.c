/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printaddress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:19 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/30 17:27:11 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(unsigned long num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += print_hex(num / 16, base);
		count += ft_putchar(base[num % 16]);
	}
	else
		count += ft_putchar(base[num % 16]);
	return (count);
}

int	ft_putaddr(void *ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	count += ft_putstr("0x");
	count += print_hex((unsigned long)ptr, base);
	return (count);
}
