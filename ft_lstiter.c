#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    while(lst)  
    {
        (*f)(lst -> content);
        lst = lst -> next;
    }
}
/*
void cnttoupper(void *content)
{
    char *str = (char *)content;
    int i = 0;
    while(str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
    //return content;
}

int main()
{
    t_list *head = ft_lstnew(strdup("a"));
    ft_lstadd_back(&head, ft_lstnew(strdup("a")));
    ft_lstadd_back(&head, ft_lstnew(strdup("2")));
    ft_lstadd_back(&head, ft_lstnew(strdup("3")));
    ft_lstadd_back(&head, ft_lstnew(strdup("4")));
    
    int i = ft_lstsize(head);
    ft_lstiter(head, cnttoupper);
    printf("%s\n", (char *)head -> content);
    printf("%d\n", i);
}
*/