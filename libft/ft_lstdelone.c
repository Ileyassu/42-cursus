/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:27:16 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/13 20:33:54 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if(lst)
    {
        (*del)(lst -> content);
        free(lst);
    }
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

    ft_lstdelone(new1, deletecontent);
    printf("%s\n", (char *)head -> content);
    //printf("i = %d\n", i);
}
*/