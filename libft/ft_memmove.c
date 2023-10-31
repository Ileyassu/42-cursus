#include "libft.h"

void *ft_memmove(void *dest, const void *src, int n)
{
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    if(d == NULL && s == NULL)
        return (NULL);

    if((s > d) || (d > s + n))
    {
        ft_memcpy(d, s, n);
    }
    else
    {
        while(n > 0 && s)
        {
            d[n] = s[n];
            n--;
        }
    }
    return (dest);

}
