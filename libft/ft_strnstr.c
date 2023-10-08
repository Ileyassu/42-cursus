#include "ft_strlen.c"
#include <unistd.h>
#include <stdio.h>

char *strnstr(const char *big,	const char *little, size_t len)
{
    const char *ptr = little;

    while(*big++ && --len > 0)
    {
        ptr = &little[0];   
        while(*big++ == *ptr++ && --len > 0)
        {
            //printf("%s\n", big);
            if(*ptr == '\0')
            {
                return (char *)big;
            }
        }
    }
    return NULL;
}

#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    size_t len = 13; // Consider the first 13 characters of haystack

    char *result = strnstr(haystack, needle, len);

    if (result != NULL) {
        printf("Found: %s\n", result); // This will print "World!"
    } else {
        printf("Not found\n");
    }

    return 0;
}






