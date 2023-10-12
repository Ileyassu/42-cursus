#include <unistd.h>
#include "ft_putchar_fd.c"
void ft_putnbr_fd(int n, int fd)
{
    size_t nbr = n;

    if(nbr < 0)
    {
        ft_putchar_fd('-', 1);
        nbr *= -1;
    }
    if(nbr <= 9)
    {
        ft_putchar_fd(nbr + '0', 1);
    }
    else
    {
        ft_putnbr_fd(nbr / 10, 1);
        ft_putnbr_fd(nbr % 10, 1);
    }
}

int main ()
{
    ft_putnbr_fd(-954437177, 1);
}