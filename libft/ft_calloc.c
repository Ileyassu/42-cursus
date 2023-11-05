/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:41:52 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:41:53 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t size, size_t count)
{
    void *n;	
    n = malloc(count * size);
	if (n != NULL)
	{
		ft_bzero(n, size * count);
		return(n);
	}

	return(NULL);
}