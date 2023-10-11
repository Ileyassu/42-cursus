#include <unistd.h>
#include "ft_bzero.c"
#include <stdlib.h>
void *ft_calloc(size_t size, size_t count)
{
    void *n;	
    n = malloc(count * size);
	if (n != NULL)
	{
		ft_bzero(n, size * count);
		return(n);
	}

	return(NULL);
}