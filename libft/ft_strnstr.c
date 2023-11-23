/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:41 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 11:08:07 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		little_len;
	const char	*ptr;
	const char	*haystack;

	if (!big && len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (*big && len >= little_len)
	{
		ptr = little;
		haystack = big;
		while (*ptr && *ptr == *haystack)
		{
			ptr++;
			haystack++;
			if (*ptr == '\0')
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
