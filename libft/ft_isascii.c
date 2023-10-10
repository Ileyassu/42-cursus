#include <unistd.h>
int		ft_isascii(int c)
{
    if(c >= 0 && c < 128)
	    return (c);
    else
    {
        return (0);
    }
}