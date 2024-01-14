/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:21:20 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/01/13 20:28:52 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_strdup(const char *str)
{
	int		n;
	char	*ptr;

	n = ft_strlen((char *)str);
	ptr = (char *)malloc(n + 1);
	if (ptr != NULL)
	{
		ft_memcpy(ptr, str, n);
		ptr[n] = '\0';
		return (ptr);
	}
	return (NULL);
}
