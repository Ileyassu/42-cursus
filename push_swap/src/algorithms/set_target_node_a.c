/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_node_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:47:02 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/26 00:21:55 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	helper(long *best_match_number, t_stack **roaming_b,
		t_stack **target_node)
{
	*best_match_number = (*roaming_b)->value;
	(*target_node) = (*roaming_b);
}

void	set_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*roaming_a;
	t_stack	*roaming_b;
	t_stack	*target_node;
	long	best_match_number;

	target_node = NULL;
	roaming_a = *stack_a;
	while (roaming_a)
	{
		roaming_b = *stack_b;
		best_match_number = LONG_MIN;
		while (roaming_b)
		{
			if (roaming_b->value < roaming_a->value
				&& roaming_b->value > best_match_number)
				helper(&best_match_number, &roaming_b, &target_node);
			roaming_b = roaming_b->next;
		}
		if (best_match_number == LONG_MIN)
			roaming_a->target = find_max_node(stack_b);
		else
			roaming_a->target = target_node;
		roaming_a = roaming_a->next;
	}
}
