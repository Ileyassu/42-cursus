char *ft_strnstr(const char *big, const char *little, size_t len)
{
    const char *ptr;

    while(*big++ && --len > 0)
    {
        ptr = little;
        while(*big++ == *ptr++ && --len > 0)
        {
            if(*ptr == '\0')
            {
                return (char *)big;
            }
        }
    }
    return NULL;
}


