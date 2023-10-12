#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_strlen.c"
char *ft_substr(char *s, unsigned int pos, size_t size)
{
    //return NULL ila string kane khawi
    if (s == NULL)
        return (NULL);

    char *ptr;
    
    size_t str_len = ft_strlen(s); //ndbro 3la length dyal s
    int n =  size - pos; //dakchi li b9a n alloki zamlboh m3a dak ptr

    //allocating ptr
    ptr = (char *)malloc((sizeof(char) * n) + 1); 
    
    if (pos >= str_len || size == 0)//safi
        return (NULL);

    char *res = ptr;//pointi 3la pos dl ptr
    
    while((n > 0) && (*(s + pos) != '\0'))
    {
        *ptr++ = *(s + pos++);
        n--;
    }
    *ptr = '\0';
    return(res);
}