/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:04 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:53:02 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*tmp1;

	cheapest_node = get_cheapest((*stack_a));
	if (cheapest_node->above_median == 1
		&& cheapest_node->target->above_median == 1)
	{
		rotate_a_b(stack_a, stack_b, cheapest_node);
		tmp1 = (*stack_b);
		while (tmp1)
		{
			tmp1 = tmp1->next;
		}
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
	{
		reverse_rotate_a_b(stack_a, stack_b, cheapest_node);
	}
	make_push(stack_a, cheapest_node, 'a');
	make_push(stack_b, cheapest_node->target, 'b');
	pb(stack_b, stack_a);
}

void	move_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	make_push(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}
