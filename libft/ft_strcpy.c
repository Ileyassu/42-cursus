#include <stdio.h>
char *ft_strcpy(char *dest, char *src)
{
    char *ptr;
    ptr = dest;
    while(*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest++ = '\0';
    return (ptr);
}