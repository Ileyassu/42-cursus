/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:45:35 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/13 11:48:50 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while(lst)
    {
        i++;
        lst = lst -> next;
    }
    return (i);
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
    printf("i = %d\n", i);
}
*/