/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:43:38 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/21 22:00:49 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	strings_length;
	size_t	strlen1;
	size_t	strlen2;
	char	*ptr;
	char	*result;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	strings_length = strlen1 + strlen2;
	ptr = (char *)malloc(strings_length + 1);
	if (ptr == NULL)
		return (NULL);
	result = ptr;
	ft_memcpy(ptr, (char *)s1, ft_strlen(s1));
	ft_memcpy(ptr + strlen1, (char *)s2, strlen2 + 1);
	*(ptr + strings_length) = '\0';
	return (result);
}
