#include <unistd.h>
#include "ft_putstr_fd.c"
void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    write(fd, "\n", 1);
}