#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last = ft_lstlast(*lst);
    last -> next = new;
}
/*
int main()
{
    t_list *head = ft_lstnew("wqwq");
    t_list *new1 = ft_lstnew("asas");
    t_list *new2 = ft_lstnew("asasa");
    t_list *new3 = ft_lstnew("asasaaaaaaa");
    t_list *new4 = ft_lstnew("tolast");
    ft_lstadd_front(&head, new1);
    ft_lstadd_front(&head, new2);
    ft_lstadd_front(&head, new3);
    ft_lstadd_back(&head, new4);
    int i = ft_lstsize(head);

    printf("last's content = %s\n", (char *)head -> next -> next -> next -> next -> content);
    //head -> next -> next = NULL;
    //t_list *last = ft_lstlast(head);
    printf("i = %d\n", i);
}
*/
