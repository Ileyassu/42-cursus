/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:08:38 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/14 07:45:28 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  *newnode;

    newnode = (t_list *)malloc(sizeof(t_list));
    if(newnode)
    {
        newnode -> next = NULL;
        newnode -> content = content;
        return (newnode);
    }
    return (newnode);
}