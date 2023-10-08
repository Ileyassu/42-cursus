#include <unistd.h>

int ft_atoi(const char *nbr)
{
    int negative_sign;
    int i = 0;
    int result = 0;
    negative_sign = 1;

    if(ptr[i] == ' ' || *ptr == '\t')
    {
        i++;
    }
    if(ptr[i] == '-')
    {
        negative_sign *= -1;
        i++;
    }
    while (ptr[i] >= '0' && ptr[i] <= '9')
    {
        result *= 10;
        if(ptr[i] >= '0' && ptr[i] <= '9')
        {
            result += ptr[i] - '0';
        }
        else
        {
            return 0;
        }
        i++;
    }

    return (negative_sign * result);
}