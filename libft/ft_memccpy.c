#include <unistd.h>

void *ft_memccpy(void *dest, const void *src, unsigned int c, unsigned int size)
{
    unsigned char *n;
    const unsigned char *m;
    int i;

    n = (unsigned char *) dest;
    m = (const unsigned char *) src;
    i = 0;
    
    if ((m == NULL) &&(n == NULL))
        return NULL;
    
    while (i < size)
    {
        n[i] = m[i];
        if (n[i] == (unsigned char) c)
        {
            return (&n[i]);
        }
        i++;
    }

    return (NULL);
}