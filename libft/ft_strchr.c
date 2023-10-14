#include <unistd.h>

char *ft_strchr(const char *str, int c)
{
   while(*str != c)
   {
        if(*str == '\0')
        {
            return NULL;
        }
        str++;
   }
   return ((char *)str);
}