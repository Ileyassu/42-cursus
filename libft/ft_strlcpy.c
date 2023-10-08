#include <unistd.h>
#include "ft_memcpy.c"
#include "ft_strlen.c"
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t srclen;

	srclen = ft_strlen((char *)src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dest, src, srclen);
		dest[srclen] = '\0';
	}
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}
#include <strings.h>

int main() {
    char dest[20];
    const char *src = "Hello, World!";

    // Copy the source string to the destination buffer with a maximum size of 10 characters
    size_t length = ft_strlcpy(dest, src, 3);

    printf("Copied string: %s\n", dest);
    printf("Length of copied string: %zu\n", length);

    return 0;
}