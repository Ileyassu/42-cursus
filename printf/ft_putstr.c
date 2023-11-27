#include "ft_printf.h"

int ft_putstr(char *s)
{
    int i;
    int count;

    i = 0;
    count = ft_strlen(s);
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return (count);
}
