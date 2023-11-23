/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:41:49 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 22:08:17 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *ptr, size_t size)
{
	unsigned char	*n;

	n = ptr;
	while (size > 0)
	{
		*n++ = 0;
		size--;
	}
}
