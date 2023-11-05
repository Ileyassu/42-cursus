/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:42:47 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:49:57 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int wordLen(const char *s, char c)
{
    int count;
    int i;

    count = 0;
    while(*s && *s++ != c)
    {
        count++;
    }
    return (count);
}

static int countWords(const char *s, char c)
{
    int i;
    int isWord;
    int count;

    i = 0;
    count = 0;
    isWord = 0;
    while(*s)
    {
        if(*s != c && isWord)
        {
            isWord = 0;
            count++;
        }
        else if(*s == c)
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
char **ft_split(const char *s, char c)
{
    char **ptr;
    int count;
    int wordlen;
    int i;

    i = 0;
    wordlen = 0;
    count = countWords(s, c);
    ptr = (char **)malloc(sizeof(char *) * count + 1);
    if(ptr == NULL)
    {
        ft_free_arr(ptr, i);
        return NULL;
    }
    while(i < count)
    {
        while(*s && *s == c)
        {
            *s++;
        }
        wordlen = wordLen((char *)s, c);
        ptr[i] = ft_strndup((char *)s, wordlen);
        if(ptr == NULL)
        {
            ft_free_arr(ptr, i);
            return NULL;
        }
        s += wordlen;
        i++;
    }
    ptr[count] = NULL;
    return ptr;
}