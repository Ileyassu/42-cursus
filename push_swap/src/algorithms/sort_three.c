/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:21:07 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 16:00:59 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three_helper(int a, int b, int c, t_stack **stack)
{
	if (a < b && a < c)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && c > a)
		sa(stack);
	else if (a > b && a > c && c > b)
		ra(stack);
	else if (a < b && a > c && b > c)
		rra(stack);
	else if (a > b && a > c)
	{
		if (b > c)
		{
			sa(stack);
			rra(stack);
		}
	}
	else if (a < b && a < c)
		sort_three_helper(a, b, c, stack);
}
