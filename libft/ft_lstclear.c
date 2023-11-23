/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:33:29 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/14 07:33:29 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *current;
    t_list *next;

    current = *lst;
    while(current)
    {   next = current -> next;
        (*del)(current -> content);
        free(current); 
        current = next;
    }
    *lst = NULL;
}
/*
void deletecontent(void *content)
{
    free(content);
}
int main()
{
    t_list *head = ft_lstnew(strdup("0"));
    t_list *new1 = ft_lstnew(strdup("1"));
    t_list *new2 = ft_lstnew(strdup("2"));
    t_list *new3 = ft_lstnew(strdup("3"));
    ft_lstadd_front(&head, new1);
    ft_lstadd_front(&head, new2);
    ft_lstadd_front(&head, new3);
    int i = ft_lstsize(head);
    ft_lstclear(&head, deletecontent);
    //free(new1);
    //ft_lstdelone(new1, deletecontent);
    //printf("%p\n", new1);
    //printf("i = %d\n", i);
    char *s = malloc(3);
    s = strdup("12");
    free(s);
    printf("%s\n", s);
}
*/