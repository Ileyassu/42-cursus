/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:28:20 by ilyas             #+#    #+#             */
/*   Updated: 2023/12/01 18:09:00 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(unsigned int nb)
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	x;

	x = ft_strlen(str);
	while (x)
	{
		if (str[x] == (char)c)
			return ((char *)str + x);
		x--;
	}
	if (str[x] == (char)c)
		return ((char *)str);
	return (NULL);
}
