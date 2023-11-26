#include "ft_printf.h"

static int	count_digits(int nb)
{
	int	digits;

	digits = 0;
	if (nb <= 0)
		digits++;
	while (nb)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

int ft_putnbr(int n)
{
    long long nbr;
    int count = 0;

    count = count_digits(n);
    nbr = n;
    if(nbr < 0)
    {
        nbr *= -1;
        ft_putchar('-');
        count += 1;
    }
    if(nbr <= 9)
        ft_putchar(nbr + '0');
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    return (count);
}