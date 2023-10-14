#include <stdio.h>
#include <unistd.h>

void *ft_memcpy(void *dest, const void *src, size_t size)
{
    unsigned char *n;
    const unsigned char *m;
    size_t i;

    n = (unsigned char *)dest;
    m = (const unsigned char *) src;
    if (size <= 0 || m == NULL || n == NULL)
        return NULL;
    
    while (--size > 0)
    {
        *n = *m;
        n++;
        m++;
    }
    *n--;
    return (dest);
}