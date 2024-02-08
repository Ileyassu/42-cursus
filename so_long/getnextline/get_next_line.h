/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:10:01 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/07 13:29:19 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
#endif
