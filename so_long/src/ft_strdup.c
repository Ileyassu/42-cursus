#include "../includes/so_long.h"

char	*ft_strdup(const char *str)
{
	int		n;
	char	*ptr;

	n = ft_strlen((char *)str);
	ptr = (char *)malloc(n + 1);
	if (ptr != NULL)
	{
		ft_memcpy(ptr, str, n);
		ptr[n] = '\0';
		return (ptr);
	}
	return (NULL);
}