#include <stdlib.h>
#include <stdio.h>
#include "ft_strlen.c"
#include "ft_strcpy.c"
#include "ft_strlcat.c"
char *ft_strjoin(char const *s1, char const *s2)
{
    int strings_length;
    char *ptr;
    char *result;

    strings_length = ft_strlen(s1) + ft_strlen((char *)s2);
    ptr = (char *)malloc(strings_length + 1);
    result = ptr;

    ft_strcpy(ptr, (char *)s1);
    ft_strlcat(ptr, s2, strings_length);
    *(ptr + strings_length + 1) = '\0';

    return (result);
}