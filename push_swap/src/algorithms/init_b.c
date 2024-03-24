/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:01 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:51:31 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	tmp = stack;
	min = LONG_MAX;
	while (tmp)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min_node(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack **a, t_stack **b)
{
	current_index(a);
	current_index(b);
	set_target_b(*a, *b);
}
