#include "../includes/so_long.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*ptr;
	const char	*haystack;

	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		ptr = little;
		haystack = big;
		while (*ptr && *ptr == *haystack)
		{
			ptr++;
			haystack++;
			if (*ptr == '\0')
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}