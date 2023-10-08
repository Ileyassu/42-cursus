#include <stdlib.h>

void *ft_memset(void *ptr, int nbr, unsigned int size)
{
    unsigned char *n;
    int            i;

    n = ptr;
    i = 0;
    while(i < size)
    {
        n[i] = nbr;
        i++;
    }

    return (n);
}

#include <stdio.h>
#include <string.h>
#include <stdio.h>
//include <string.h>

int main() {
    int str[20]; // Declare a character array

    // Initialize the str array with 'A' character using memset
    ft_memset(str, 5, sizeof(str));

    // Print the result
    printf("After memset: %d\n", str[2]);

    return 0;
}





