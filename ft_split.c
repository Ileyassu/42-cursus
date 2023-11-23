/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:38:54 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/22 11:44:45 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlength(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s++ != c)
	{
		count++;
	}
	return (count);
}

static int	countwords(const char *s, char c)
{
	int	isword;
	int	count;

	count = 0;
	isword = 1;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c && isword)
		{
			isword = 0;
			count++;
		}
		else if (*s == c)
		{
			isword = 1;
		}
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *str, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr != NULL)
	{
		while (str[i] && i < size)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}

static char	**ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		count;
	int		i;

	i = 0;
	count = countwords(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = ft_strndup((char *)s, wordlength((char *)s, c));
		if (ptr[i] == NULL)
		{
			ft_free_arr(ptr, i);
			return (NULL);
		}
		s += wordlength((char *)s, c);
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}
