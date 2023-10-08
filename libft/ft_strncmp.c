#include <unistd.h>
#include <stdio.h>
int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    int i;

    i = 0;
    while ((*str1 && *str2) && (*str1 == *str2) && n <= 0)
    {
        printf("%d\n", (int)i);
        str1++;
        str2++;
        n--;
    }
    return (*str1 - *str2);
}
#include <string.h>

int main()
{
    int n = ft_strncmp("zbia", "zbi", 4);
    printf("%d\n", n);
}