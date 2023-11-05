/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:19 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/04 18:46:23 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char uppercase(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    else
        return ft_tolower(c);
}
*/

void uppercase(unsigned int index, char *ch)
{
    if(ch[index] >= 'a' && ch[index] <= 'z')
    {
        ch[index] -= 32;
        write(1, &ch[index], 1);
    }
}

// char str[] = "hello";
// ft_striteri(str, uppercase);

int main() 
{
    /*
    char buffer = 'a';
    if(ft_isalpha(buffer))
    {
        printf("jbto\n");
    }


    char bufferr = '7';
    if(ft_isdigit(bufferr))
    {
        printf("jbto walakine ra9m\n");
    }

    char bufferrr = '7';
    if(ft_isalnum(bufferrr))
    {
        printf("jbthhom bjoj\n");
    }

    char str[] = "12345";

    int i = ft_strlen(str);
    printf("len = %d\n", i);

    char sstr[2];

   ft_memset(sstr,'$',7);
   puts(sstr);

    char sensitive_data[50] = "This is a secret password";

    // Clear sensitive_data using bzero
    bzero(sensitive_data, sizeof(sensitive_data));

    // Check if the data has been zeroed out
    if (strlen(sensitive_data) == 0) {
        printf("The sensitive data has been successfully cleared.\n");
    } else {
        printf("The data was not cleared properly.\n");
    }
    const char src[50] = "https://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before ft_memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 9);
   printf("After ft_memmove dest = %s, src = %s\n", dest, src);

    char source[] = "This is a long source string.";
    char destination[10];

    int len = ft_strlcpy(destination, source, sizeof(destination));

    printf("Copied: %s\n", destination);
    printf("Length of source: %d\n", len);

   int len;
   const char str[] = "https://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
    return 0;

    const char str[] = "https://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);
       char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "ABCDEF", 6);
   memcpy(str2, "abcdef", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1\n");
   } else if(ret < 0) {
      printf("str1 is less than str2\n");
   } else {
      printf("str1 is equal to str2\n");
   }
    char str[] = "abcdef";
    char *ptr = ft_substr(str, 3, 2);
    printf("%s", ptr);

    char str1[] = "abcd";
    char str2[] = "efjh";
    char *ptr = ft_strjoin(str1, str2);

    printf("ptr = %s\n", ptr);
    const char *input = "  \t   Hello, worldsssssss!                 \t  ";
    printf("string: '%s'\n", input);
    const char *chars_to_trim = " \t";

    char *trimmed = ft_strtrim(input, chars_to_trim);

    printf("Trimmed string: '%s'\n", trimmed);

    free(trimmed);


    char *ptr = ft_itoi(-10);
    printf("%s\n", ptr);

    const char *text = "This  is a simple";
    int words = countWords(text);

    printf("Word count: %d\n", words);
    char string[50] = "  Hello world w  rr";
   // Extract the first token
   char ** token = ft_split(string, ' ');
   printf( "%s\n", token[1] ); //printing the token
    char *ptr = ft_strmapi("Hello, World!", uppercase);
    printf("%s\n", ptr);
    */
    char str[] = "hello";
    ft_striteri(str, uppercase);
    return(0);
}