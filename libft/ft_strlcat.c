#include <unistd.h>
#include "ft_memcpy.c"
#include <stdio.h>
int ft_strlen(const char *str)
{
    int i = 0;
    while(*str)
    {
        str++;
        i++;
    }
    return (i);
}
int ft_strlcat(char *dest, const char *src, size_t size)
{
    int destlen;
    int srclen;
    int result;

    destlen = ft_strlen(dest);
    srclen = ft_strlen(src);
    if(destlen > size)
    {
        return size + srclen;
    }
    result = destlen + srclen;
    if (srclen < size - destlen)
	{
		ft_memcpy(dest + destlen, src, srclen);
		dest[destlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dest + destlen, src, size - destlen - 1);
		dest[size - 1] = '\0';
	}
	return (result);
}
#include <string.h>
int main()
{
    char dest[20] = "abcd ";
    const char src[20] = "efjh";
    int n = ft_strlcat(dest, src, 21);

    printf("%s\n", dest);
    printf("%d\n", n);
}