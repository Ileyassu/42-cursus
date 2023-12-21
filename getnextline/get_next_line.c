#include "get_next_line.h"

char *cutline(char *str)
{
    int i = 0;
    int len = 0;
    char *line;
    while(str[len] && str[len] != '\n')
        len++;
    line = malloc(len + 1);
    if (!line)
        return (NULL);
    while(str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char 
char *get_next_line(int fd)
{
    static char *var;
    char *buffer;
    int bytesRead;
    char *line;

    free(var);
    var = NULL;
    bytesRead = 1;
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    while (bytesRead > 0 && !ft_strchr(buffer, '\n'))
    {
        bytesRead = read(fd, buffer, BUFFER_SIZE);
        if (bytesRead < 0)
        {
            free(var);
            free(buffer);
            return (NULL);
        }
        if (bytesRead == 0)
            break;
        buffer[bytesRead] = '\0';
        var = ft_strjoin(var, buffer);
    }
    free(buffer);
    //printf("var = %s", var);
    //printf("line = %s", line);
    line = cutline(var);
    var = ft_backup(var);
}

int main()
{
    char *line;
    char *line1;
    char *line2;
    int fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    line1 = get_next_line(fd);
    printf("%s", line1);
    line2 = get_next_line(fd);
    printf("%s", line2);
}