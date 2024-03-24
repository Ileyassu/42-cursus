/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target_node_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:47:02 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:56:19 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_target_node_helper(t_stack *roaming_a, t_stack *roaming_b,
		t_stack *target_node, long best_match_number)
{
	while (roaming_b != NULL)
	{
		if (roaming_a->value > roaming_b->value
			&& roaming_b->value > best_match_number)
		{
			best_match_number = roaming_b->value;
			target_node = roaming_b;
		}
		roaming_b = roaming_b->next;
	}
}

void	set_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*roaming_a;
	t_stack	*roaming_b;
	t_stack	*target_node;
	long	best_match_number;

	target_node = NULL;
	best_match_number = LONG_MIN;
	roaming_a = *stack_a;
	while (roaming_a != NULL)
	{
		roaming_b = *stack_b;
		set_target_node_helper(roaming_a, roaming_b, target_node,
			best_match_number);
		if (best_match_number == LONG_MIN)
			roaming_a->target = find_max_node(stack_b);
		else
			roaming_a->target = target_node;
		roaming_a = roaming_a->next;
	}
}
