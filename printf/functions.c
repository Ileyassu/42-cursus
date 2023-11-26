#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
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