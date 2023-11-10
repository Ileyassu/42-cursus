/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:03 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/08 11:54:55 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int pos, size_t size)
{
	char	*res;
	char	*ptr;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (pos > str_len || size == 0)
		return (NULL);
	pos--;
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	res = ptr;
	while ((size > 0) && (*(s + pos) != '\0'))
	{
		*ptr++ = *(s + pos++);
		size--;
	}
	*ptr = '\0';
	return (res);
}
