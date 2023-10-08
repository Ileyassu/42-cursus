#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void * ft_memmove(void* dest, const void* src, unsigned int n)
{
    char *tmp;
    tmp = (char *)malloc(sizeof(char) * n);

    if (tmp == NULL)
    {
        return (NULL);
    }
    else 
    {
        unsigned char *d = (unsigned char *)dest;
        const unsigned char *s = (const unsigned char *)src;

        if ((d == NULL) &&(s == NULL))
            return (NULL);
        int i = 0;
        while(i < n) //till n
        {
            //Copy byte by byte
            tmp[i] = s[i];
            i++;
        }
        i = 0;
        while(i < n)
        {
            d[i] = tmp[i];
            i++;
        }
        free(tmp);
        return dest;
        }
        
}