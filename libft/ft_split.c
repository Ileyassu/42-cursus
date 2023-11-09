/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:38:54 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/09 13:52:56 by ibenaiss         ###   ########.fr       */
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

static void	ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	int		count;
	int		wordlen;
	int		i;

	i = 0;
	wordlen = 0;
	count = countwords(s, c);
	ptr = (char **)malloc(sizeof(char *) * count + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		wordlen = wordlength((char *)s, c);
		ptr[i] = ft_strndup((char *)s, wordlen);
		if (ptr[i] == NULL)
		{
			ft_free_arr(ptr, i);
			return (NULL);
		}
		s += wordlen;
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}
int main()
{
    int i = 0;
    char **ptr = ft_split("qqq ww  ww e  ewew ewe", ' ');
    while(ptr[i])
    {
       printf("%s\n", ptr[i++]); 
    }
}
