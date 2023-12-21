#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_strlen(char *str);
char *ft_strncpy(char *dest, const char *src, int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
#endif


