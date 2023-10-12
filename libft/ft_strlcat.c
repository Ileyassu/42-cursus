#include <unistd.h>
#include "ft_memcpy.c"
#include <stdio.h>
int ft_strlenn(const char *str)
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

    destlen = ft_strlenn(dest);
    srclen = ft_strlenn(src);
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