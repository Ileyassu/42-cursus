#include "ft_printf.h"

int ft_putnbr_base(long nbr, char *base, int count)
{
    int len;
    char c;

    len = ft_strlen(base);
    if(nbr < 0)
    {
        nbr *= -1;
        ft_putchar('-');
    }
    if(nbr < len)
    {
        c = base[nbr];
        ft_putchar(c);
        count++;
    }
    else
    {
        ft_putnbr_base(nbr / len, base, count);
        ft_putnbr_base(nbr % len, base, count);
    }
    return (count);
}

void hexabase(int nbr)
{
    int count;

    count = 0;
    ft_putnbr_base(nbr, "0123456789abcdef", count);
}