#include "ft_memcpy.c"
#include "ft_strlen.c"
#include "ft_strnstr.c"
#include "ft_strchr.c"
#include <stdlib.h>
#include <stdio.h>
char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	char	*result;

	while (*s1 && ft_strchr(set, (char)*s1) != 0)
    {
        s1++;
    }
    len = ft_strlen(s1);

    while(len > 0 && ft_strchr(set, *(s1 + len)) != 0)
    {
        len--;
    }
    //printf("%d\n",len);
    result = (char *)malloc(len);
    
    ft_memcpy(result,(char *)s1, len + 2);
    //printf("%s\n",result);
    return result;
}
/*
int main() {
    const char *input = "  \t   Hello, worldsssssss!   \t  ";
    printf("string: '%s'\n", input);
    const char *chars_to_trim = " \t";

    char *trimmed = ft_strtrim(input, chars_to_trim);

    printf("Trimmed string: '%s'\n", trimmed);

    free(trimmed);

    return 0;
}*/