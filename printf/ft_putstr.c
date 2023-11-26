#include "ft_printf.h"

int ft_putstr(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
        count++;
    }
    return (count);
}
