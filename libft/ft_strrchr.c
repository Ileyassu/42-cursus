#include <unistd.h>
#include <stdio.h>
#include <string.h>
char *ft_strrchr(const char *str, int c)
{
    int i;
    while (*str)
    {
        str++;
    }
    str--;
    while (*str--)
    {
        if (str[i] == c)
        {
            return (char *)str;
        }
    }
    return (NULL);
}

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}