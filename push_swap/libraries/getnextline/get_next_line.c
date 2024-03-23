/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:09:29 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/12/22 19:56:46 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_static_var(int fd, char *var)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(var, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(var);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		var = ft_strjoin(var, buffer);
	}
	free(buffer);
	return (var);
}

static char	*cutline(char *str)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	if (!str[i])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_backup(char *var)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (var[i] && var[i] != '\n')
		i++;
	if (!var[i])
	{
		free(var);
		return (NULL);
	}
	line = malloc((ft_strlen(var) - i + 1) * sizeof(char));
	if (!line)
	{
		free(var);
		return (NULL);
	}
	i++;
	j = 0;
	while (var[i])
		line[j++] = var[i++];
	line[j] = '\0';
	free(var);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*var;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	var = get_static_var(fd, var);
	if (!var)
		return (NULL);
	line = cutline(var);
	var = ft_backup(var);
	return (line);
}
