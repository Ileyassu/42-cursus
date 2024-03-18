/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:21:56 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/17 23:10:58 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack, char *str)
{
    t_stack *tmp;

    if (*stack && (*stack)->next)
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
        ft_printf("%s\n", str);
    }
}

void sa(t_stack **stack_b)
{
    swap(stack_b, "sa\n");
}

void sb(t_stack **stack_b)
{
    swap(stack_b, "sb\n"); // Reuse the sa function
}
void push(t_stack **stack_a, t_stack **stack_b, char *str)
{
    
}
// void ss(t_stack **stack_a, t_stack **stack_b, char *str)
// {
//     swap(stack_a, NULL);
//     swap(stack_b, "ss\n");

// }