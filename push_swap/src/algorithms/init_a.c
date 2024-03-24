/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:20:58 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:49:52 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target->above_median == 1)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;
	t_stack	*tmp;

	tmp = stack;
	cheapest_node = NULL;
	if (!tmp)
		return ;
	cheapest_value = LONG_MAX;
	while (tmp)
	{
		if (tmp->push_cost < cheapest_value)
		{
			cheapest_value = tmp->push_cost;
			cheapest_node = tmp;
		}
		tmp = tmp->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	((*stack_a)->target = NULL);
	((*stack_b)->target = NULL);
	current_index(stack_a);
	current_index(stack_b);
	set_target_node(stack_a, stack_b);
	calculate_cost(*stack_a, *stack_b);
	set_cheapest(*stack_a);
}
