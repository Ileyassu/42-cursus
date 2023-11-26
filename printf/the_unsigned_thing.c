#include "ft_printf.h"

int unsigned_putnbr(unsigned int nbr)
{
    int count; 
    
    count = 0;
    if(nbr <= 9)
        ft_putchar(nbr + '0');
    else
    {
        unsigned_putnbr(nbr / 10);
        unsigned_putnbr(nbr % 10);
        count++;
    }
    return (count);
}