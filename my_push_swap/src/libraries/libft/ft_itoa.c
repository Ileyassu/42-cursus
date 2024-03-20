/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/23 14:42:00 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*checkif_zero(char *ptr)
{
	ptr = malloc(2);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

static char	*isposfunc(long long temp, char *ptr, size_t len, long long nbr)
{
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr += len;
	*ptr = '\0';
	while (nbr > 0)
	{
		ptr--;
		*ptr = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ptr);
}

static char	*isnegfunc(long long temp, char *ptr, size_t len, long long nbr)
{
	temp *= -1;
	nbr *= -1;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	ptr = (char *)malloc(len + 2);
	if (ptr == NULL)
		return (NULL);
	ptr += len + 1;
	*ptr = '\0';
	while (nbr > 0)
	{
		ptr--;
		*ptr = (nbr % 10) + '0';
		nbr /= 10;
	}
	ptr -= 1;
	*ptr = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	char		*ptr;
	long long	temp;
	size_t		len;

	ptr = NULL;
	len = 0;
	if (n == 0)
	{
		ptr = checkif_zero(ptr);
		return (ptr);
	}
	nbr = n;
	temp = nbr;
	if (n < 0)
		ptr = isnegfunc(temp, ptr, len, nbr);
	else
		ptr = isposfunc(temp, ptr, len, nbr);
	return (ptr);
}
