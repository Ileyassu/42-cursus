/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/08 13:59:37 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*checkif_zero(char *ptr)
{
	ptr = (char *)malloc(3);
	if (ptr == NULL)
		return (NULL);
	*ptr = '0';
	return (ptr);
}

static void	check_negative(long long *nbr, size_t *isneg_num)
{
	*nbr *= -1;
	*isneg_num = 1;
}

static char	*tempfunc(size_t temp, char *ptr, size_t len, long long nbr)
{
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	ptr = (char *)malloc(len + 2);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr += len + 1;
	*ptr = '\0';
	ptr--;
	while (nbr > 0)
	{
		ptr--;
		*ptr = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ptr);
}

char	*ft_itoi(int n)
{
	long long	nbr;
	char		*ptr;
	size_t		temp;
	size_t		len;
	size_t		isneg_num;

	ptr = NULL;
	isneg_num = 0;
	len = 0;
	if (n == 0)
		return (ptr = checkif_zero(ptr));
	nbr = n;
	if (nbr < 0)
		check_negative(&nbr, &isneg_num);
	temp = nbr;
	ptr = tempfunc(temp, ptr, len, nbr);
	if (isneg_num)
	{
		ptr--;
		*ptr = '-';
	}
	return (ptr);
}
