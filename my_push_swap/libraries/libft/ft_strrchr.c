/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:44 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 11:08:12 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
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
