#include <unistd.h>
int ft_isdigit(const char c)
{
    if(c >= '0' && c <= '9')
    {
        return(c);
    }
    else
    {
        return(0);
    }
}