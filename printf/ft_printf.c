/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:12:38 by ilyas             #+#    #+#             */
/*   Updated: 2023/11/27 20:27:44 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdlib.h>

int behindthescene(va_list ap, char c)
{
	int count;

	count = 0;
	if(c == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if(c == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if(c == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if(c == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if(c == 'x')
		count = hexabase(va_arg(ap, int)) - 2;
	else if(c == 'p')
		count = printaddress(va_arg(ap, unsigned long *));
	else if(c == 'u')
		count = unsigned_putnbr(va_arg(ap, unsigned int));
	else if(c == 'X')
		count = ultra_hexabase(va_arg(ap, int)) - 2;
	else if(c == '%')
		count = ft_putchar('%');
	return (count);
}
int ft_printf(char *str, ...)
{
	va_list ap;
	int i;
	int count;
	
	i = 0;
	count = 0;
	va_start(ap, str);
	while(str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", (str[i + 1])))
		{
			count += behindthescene(ap, str[i + 1]);
			if(str[i + 1] != '\0')
				i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	return count;
}