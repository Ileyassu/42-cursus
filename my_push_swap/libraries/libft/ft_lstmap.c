/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:35 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/14 11:46:18 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    ft_size *new_list = NULL;
    ft_size *current;
    while(lst)
    {
        void *newnode;

        newnode = ft_lstnew((f*)(lst -> content));
        if(!newnode)
        {
            ft_lstclear(&lst, del);
            return (NULL);
        }
        else
        {
            current -> next = newnode;
            ft_lstadd_back(&lst, newnode);
        }
        lst = lst -> next;
    }
    return (newlist);
}