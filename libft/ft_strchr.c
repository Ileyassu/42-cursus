#include <unistd.h>

char *ft_strchr(const char *str, int c)
{
   while(*str != c)
   {
        if(*str == '\0')
        {
            return NULL;
        }
        *str++;
   }
   return ((char *)str);
}
#include <stdio.h>
#include <string.h>

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}