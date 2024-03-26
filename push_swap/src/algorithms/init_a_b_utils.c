/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:20:56 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/26 00:24:48 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*find_max_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max_node;
	long	max;

	max_node = NULL;
	if (!*stack)
		return (NULL);
	tmp = *stack;
	max = tmp->value;
	max_node = tmp;
	while (tmp)
	{
		if (max < tmp->value)
		{
			max = tmp->value;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

void	current_index(t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	int		median;

	if (!stack)
		return ;
	median = get_stack_size(*stack) / 2;
	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i;
		if (i <= median)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
		++i;
	}
}
