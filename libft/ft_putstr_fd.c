#include <unistd.h>
#include "ft_strlen.c"
void ft_putstr_fd(char *s, int fd)
{
    write(fd, s, ft_strlen(s));
}