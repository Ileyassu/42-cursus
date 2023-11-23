/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:45:48 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 21:59:24 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, (char)*s1) != NULL)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, *(s1 + len - 1)) != 0)
	{
		len--;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, (char *)s1, len + 1);
	result[len] = '\0';
	return (result);
}
