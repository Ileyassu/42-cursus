
#include "libft.h"

static int wordLen(char *s, char c)
{
    int count;
    while(*s && *s++ !== c)
    {
        count++;
    }
    return (count);
}

static countWords(char *s, char c)
{
    int i;
    int isWord;
    int count;

    i = 0;
    count = 0;
    isWord = 1;
    while(*s)
    {
        if(*s != c && isWord)
        {
            isWord == 0;
            count++;
        }
        else(*s == c)
        {
            isWord = 1;
        }
        s++;
    }
    return (count);
}
static char *ft_strndup(const char *str, int size)
{
    char *ptr;
    char *tmp;
    int i;

    i = 0;
    ptr = (char *)malloc(sizeof(char) * size + 1);
    tmp = ptr;
    
    if(ptr != NULL)
    {
        while(str[i] && i < size)
        {
            ptr[i] = str[i];
            i++;
        }
        ptr[i] = '\0';
        return (ptr);
    }
    return (NULL);
}
static void	ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}
char **ft_split(char *s, char c)
{
    char **ptr;
    int count;
    int wordlen;
    int i;

    i = 0;
    wordlen = 0;
    count = countWords(s, c)
    ptr = (char **)malloc(sizeof(char *) * count + 1);
    if(ptr == NULL)
        ft_free_arr(ptr, i);
        return NULL;

    while(i < count)
    {
        while(*s && *s == c)
        {
            *s++;
        }
        wordlen = wordLen(s, c);
        ptr[i] = ft_strndup(s, wordlen);
        if(ptr == NULL)
            ft_free_arr(ptr, i)
            return NULL;
    }
    ptr[count] = NULL;
    return ptr;
}
