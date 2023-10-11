#include <unistd.h>
#include "ft_strlen.c"
#include "ft_memcpy.c"
#include <stdlib.h>
#include <stdio.h>
char *ft_strdup(const char *str)
{
    int n = ft_strlen((char *)str);
    char *ptr;

    ptr = (char *)malloc(n + 1);
    //int i = 0;
    
    if(ptr != NULL)
    {
        ft_memcpy(ptr, str, n);
        //printf("%s", ptr);
        ptr[n] = '\0';
        return (ptr);

    }
    return (NULL);
}