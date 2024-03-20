/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:43:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 22:00:31 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	if (!dst && !n && src)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < n)
		i++;
	while (src[j] != '\0' && (i + j + 1) < n)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < n)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
