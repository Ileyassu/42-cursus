#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr =  (const unsigned char *)s;
    unsigned char *m = (unsigned char *)&c;

    if(n < 0)
    {
        return NULL;
    }
    printf("%s\n", ptr);
    while(n > 0)
    {
        if (*ptr == *m)
        {
            return (void *)ptr;
        }
        ptr++;
        n--;
    }
    return (NULL);
}