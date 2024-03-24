/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:20:43 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:32:44 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
	{
		push(stack_a, stack_b);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (*stack_a)
	{
		push(stack_b, stack_a);
		ft_printf("pb\n");
	}
}
