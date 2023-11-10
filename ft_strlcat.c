/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:43:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/08 11:35:00 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	result;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= size)
	{
		return (size + srclen);
	}
	result = destlen + srclen;
	if (srclen <= size - destlen)
	{
		ft_strlcpy(dest + destlen, src, srclen + 1);
		dest[destlen + srclen] = '\0';
	}
	else
	{
		ft_strlcpy(dest + destlen, src, size - destlen );
		destlen = ft_strlen(dest);
		dest[destlen] = '\0';
	}
	return (result);
}