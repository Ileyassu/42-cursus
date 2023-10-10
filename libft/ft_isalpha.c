#include <unistd.h>
int ft_isalpha(const char c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return(c);
    }
    else
    {
        return(0);
    }
}