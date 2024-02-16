/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:45 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 18:42:09 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		*d;
	size_t				i;

	if (dest == src)
		return (dest);
	i = 0;
	ptr = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (n == 0)
		return (d);
	if (n > 0)
	{
		while (n-- > 0)
		{
			d[i] = ptr[i];
			i++;
		}
		return ((char *)dest);
	}
	return (NULL);
}
