/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:41:46 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/07 16:00:21 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *pt)
{
	int	negative_sign;
	int	i;
	long long	result;

	result = 0;
	i = 0;
	negative_sign = 1;
	    while (pt[i] == ' ' || pt[i]=='\n' || pt[i]=='\t' ||
        pt[i]=='\v' || pt[i]=='\f' || pt[i]=='\r')
		i++;
	if (pt[i] == '-')
	{
		negative_sign *= -1;
		i++;
	}
	else if (pt[i] == '+')
	{
		i++;
	}
	while (pt[i] >= '0' && pt[i] <= '9' )
	{
		result *= 10;
		if (pt[i] >= '0' && pt[i] <= '9')
			result += pt[i] - '0';
		else
			return (0);
		i++;
	}

	return (negative_sign * result);
}