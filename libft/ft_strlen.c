#include <unistd.h>
#include <stdio.h>
int ft_strlen(const char *str)
{
    int i = 0;

    while(*str)
    {
        str++;
        i++;
    }
    return (i);
}