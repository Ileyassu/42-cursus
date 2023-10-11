#include <unistd.h>

int ft_toupper(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return (c + 32);
    }
}
#include <stdio.h>
#include <ctype.h>

int main () {
   int i = 0;
   char c;
   char str[] = "TUTORIALS POINT";
	
   while( str[i] ) {
      putchar(tolower(str[i]));
      i++;
   }
   
   return(0);
}