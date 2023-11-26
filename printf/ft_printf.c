#include "ft_printf.h"
#include<stdlib.h>

void behindthescene(va_list ap, char c)
{
	//int count;

	//count = 0;
	if(c == 'c')
		ft_putchar(va_arg(ap, int));
	else if(c == 's')
		ft_putstr(va_arg(ap, char *));
	else if(c == 'd')
		ft_putnbr(va_arg(ap, int));
	else if(c == 'x')
		hexabase(va_arg(ap, int));
	else if(c == 'p')
		printaddress(va_arg(ap, unsigned long *));
	else if(c == 'u')
		unsigned_putnbr(va_arg(ap, unsigned int));
	else if(c == '%')
		ft_putchar('%');

	//return (count);
}
int ft_printf(char *str, ...)
{
	va_list ap;
	int i;
	int count;
	i = 0;
	count = 0;
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", (str[i + 1])))
		{
			behindthescene(ap, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	return count;
}

int main()
{
	//int n = 42;
	//ft_printf("%%%");
	ft_printf("%%%");
}