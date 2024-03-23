/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:41:46 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/19 02:22:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *pt)
{
	int			negative_sign;
	int			i;
	long		result;

	result = 0;
	i = 0;
	negative_sign = 1;
	while (pt[i] && (pt[i] == ' ' || (pt[i] >= '\t' && pt[i] <= '\r')))
		i++;
	if (pt[i] == '-' || pt[i] == '+')
	{
		if (pt[i] == '-')
			negative_sign *= -1;
		i++;
	}
	while (pt[i] >= '0' && pt[i] <= '9')
	{
		result = result * 10 + pt[i] - 48;
		i++;
	}
	return (negative_sign * result);
}
