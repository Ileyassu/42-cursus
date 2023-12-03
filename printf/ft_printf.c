/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:38 by ilyas             #+#    #+#             */
/*   Updated: 2023/12/03 16:58:06 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	behindthescene(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (c == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (c == 'x')
		count = ft_putnbr_base((unsigned int)va_arg(ap, long), 16, 0);
	else if (c == 'p')
		count = ft_putaddr(va_arg(ap, void *));
	else if (c == 'u')
		count = unsigned_putnbr(va_arg(ap, unsigned int));
	else if (c == 'X')
		count = ft_putnbr_base((unsigned int)va_arg(ap, long), 16, 1);
	else if (c == '%')
		count = ft_putchar('%');
	else
		count = -1;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (0);
		else if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			count += behindthescene(ap, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
