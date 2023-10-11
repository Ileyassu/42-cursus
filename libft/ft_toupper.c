#include <unistd.h>

int ft_toupper(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return (c - 32);
    }
}
