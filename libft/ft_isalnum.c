#include <unistd.h>
#include "ft_isalpha.c"
#include "ft_isdigit.c"

int ft_isalnum(const char c)
{
    if((ft_isalpha(c)) || (ft_isdigit(c)))
    {
        return c;
    }
    else
    {
        return 0;
    }
}