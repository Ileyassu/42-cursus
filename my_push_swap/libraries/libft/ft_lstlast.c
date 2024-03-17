#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    int i = ft_lstsize(lst) - 1;
    while(i > 0)
    {
        //printf("i = %d\n", i);
        lst = lst -> next;
        i--;
    }
    return (lst);
}
/*
int main()
{
    t_list *head = ft_lstnew("wqwq");
    t_list *new1 = ft_lstnew("asas");
    t_list *new2 = ft_lstnew("asasa");
    t_list *new3 = ft_lstnew("asasaaaaaaa");

    ft_lstadd_front(&head, new1);
    ft_lstadd_front(&head, new2);
    ft_lstadd_front(&head, new3);

    int i = ft_lstsize(head);

    //head -> next -> next = NULL;
    t_list *last = ft_lstlast(head);
    printf("last one = %s\n", (char *)last -> content);
}
*/