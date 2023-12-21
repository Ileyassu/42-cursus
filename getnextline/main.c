#include "get_next_line.h"


int main()
{
    int fd = open("test.txt", 'R');
    static char *var;
    char *buffer;
    int bytesRead;
    char *line;

    var = NULL;
    bytesRead = 1;
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    while (bytesRead > 0)
    {
        bytesRead = read(fd, buffer, BUFFER_SIZE);
        if (bytesRead < 0)
        {
            free(var);
            free(buffer);
            //return (NULL);
        }
        buffer[BUFFER_SIZE] = '\0';
        var = ft_strjoin(var, buffer);
        if((ft_strchr(buffer, '\n')))
            break;
    }
    free(buffer);
    line = cutline(var);
    printf("%s", line);
}