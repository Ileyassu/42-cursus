#include <unistd.h>

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
    const unsigned char *s1 = (const unsigned char *)str1;
    const unsigned char *s2 = (const unsigned char *)str2;
    int i = 0;

    if(s1 == NULL || s2 == NULL || n <= 0)
    {
        return (0);
    }
    while (n > 0 && *s1 == *s2)
    {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}

#include <string.h>
#include <stdio.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "ABCDEF", 6);
   memcpy(str2, "abcdef", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1\n");
   } else if(ret < 0) {
      printf("str1 is less than str2\n");
   } else {
      printf("str1 is equal to str2\n");
   }
   
   return(0);
}