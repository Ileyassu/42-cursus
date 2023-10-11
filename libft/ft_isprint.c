#include <unistd.h>

int ft_isprint(char c)
{
    if(c >= 0 && 32 || c == 127)
    {
        return (0);
    }
    return(c);
}