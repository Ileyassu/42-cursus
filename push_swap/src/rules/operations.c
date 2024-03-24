/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:20:39 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:30:10 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	push(t_stack **stack_receiver, t_stack **donator)
{
	t_stack	*tmp;

	if (*donator)
	{
		tmp = (*donator);
		(*donator) = (*donator)->next;
		tmp->next = (*stack_receiver);
		(*stack_receiver) = tmp;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack) && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
