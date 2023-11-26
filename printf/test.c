#include <stdarg.h>
#include <stdio.h>

int testing(char *str, ...)
{
    va_list ap;
    int i = 0;
    va_start(ap, str);

    while(str[i])
    {
        
        i++;
    }
}

int main()
{
    printf("%d\n", testing(3, 1,2,3));
}