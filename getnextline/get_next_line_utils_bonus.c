/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:09:55 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/12/22 18:09:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

char	*ft_strdup(const char *str)
{
	int		n;
	char	*ptr;

	n = ft_strlen((char *)str);
	ptr = (char *)malloc(n + 1);
	if (ptr != NULL)
	{
		ft_strncpy(ptr, str, n);
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	strings_length;
	size_t	strlen1;
	size_t	strlen2;
	char	*ptr;
	char	*result;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s1 && !s2)
		return (NULL);
	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	strings_length = strlen1 + strlen2;
	ptr = (char *)malloc(strings_length + 1);
	if (ptr == NULL)
		return (NULL);
	result = ptr;
	ft_strncpy(ptr, (char *)s1, ft_strlen(s1));
	ft_strncpy(ptr + strlen1, (char *)s2, strlen2 + 1);
	*(ptr + strings_length) = '\0';
	free(s1);
	return (result);
}
