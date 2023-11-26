#include "ft_printf.h"
#include<stdlib.h>

int printaddress(unsigned long *n)
{
    unsigned long nbr = (unsigned long)n;
    char address[20];
    char *base;
    int size;
    int count;

    count = 0;
    base = (char *)malloc(17);
    base = "0123456789abcdef";
    size = sizeof(address);
    //nbr = (unsigned long) ptr;
    address[size] = '\0';
    size--;
    while(nbr > 0)
    {
        address[size] = base[nbr % 16];
        nbr /= 16;
        size--;
        count++;
    }
    free(base);
    write(1, "0x", 2);
    write(1, address, sizeof(address));
    return (count);
}