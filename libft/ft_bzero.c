#include <unistd.h>

void ft_bzero(void *ptr, size_t size)
{
    unsigned char *n;
    int i;

    n = ptr;
    i = 0;
    while (i < size)
    {
        n[i] = 0;
        i++;
    }
}