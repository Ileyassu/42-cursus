#include "ft_printf.h"


int printf(char *str, ...)
{
	va_list ap;
	int i;

	i = 0;
	va_start(ap, str);
	while(str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", (str[i + 1])))
		{

		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}