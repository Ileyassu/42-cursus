#include <unistd.h>
#include <stdio.h>
#include <string.h>
char *ft_strrchr(const char *str, int c)
{
    int i;
    while (*str)
    {
        str++;
    }
    str--;
    while (*str--)
    {
        if (str[i] == c)
        {
            return (char *)str;
        }
    }
    return (NULL);
}