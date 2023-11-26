#include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

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
    int count;

    count = count_digits(n);
    nbr = n;
    if(nbr < 0)
    {
        nbr *= -1;
        ft_putchar('-');
    }
    if(nbr <= 9)
    {
        ft_putchar(nbr + '0');
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    return (count);
}

void ft_putnbr_base(long nbr, char *base, int count)
{
    int len;
    char c;

    len = strlen(base);
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

}

void printaddress(void *ptr)
{
    unsigned long nbr;
    char address[20];
    char *base;
    int size;

    base = (char *)malloc(17);
    base = "0123456789abcdef";
    size = sizeof(address);
    nbr = (unsigned long) ptr;
    address[size] = '\0';
    size--;
    while(nbr > 0)
    {
        address[size] = base[nbr % 16];
        nbr /= 16;
        size--;
    }
}

char	*ft_strrchr(const char *str, int c)
{
	size_t	x;

	x = ft_strlen(str);
	while (x)
	{
		if (str[x] == (char)c)
			return ((char *)str + x);
		x--;
	}
	if (str[x] == (char)c)
		return ((char *)str);
	return (NULL);
}

// int main()
// {
//     int n = 42;
//     void *ptr = (void *)&n;
//     printaddress(ptr);
//     printf("%p\n", &n);
// }