/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:48 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/08 11:48:51 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*result;

	while (*s1 && ft_strchr(set, (char)*s1) != NULL)
	{
		s1++;
	}
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, *(s1 + len)) != 0)
	{
		len--;
	}
	len--;
	result = (char *)malloc(len);
	ft_memcpy(result, (char *)s1, len + 1);

	return (result);
}
