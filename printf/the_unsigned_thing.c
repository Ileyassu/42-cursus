#include "ft_printf.h"

int unsigned_putnbr(unsigned int nbr)
{
    int count; 
    
    count = count_digits(nbr);
    if(nbr <= 9)
        ft_putchar(nbr + '0');
    else
    {
        unsigned_putnbr(nbr / 10);
        unsigned_putnbr(nbr % 10);
    }
    return (count);
}