/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:12:19 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/16 13:53:36 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void stack_add_bottom(t_stack **stack, t_stack *new)
{
    t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

static t_stack *init_stack(int num)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = num;
    return (new);
}

t_stack *add_to_stack(char **arr_of_num)
{
    t_stack *stack_a;
    long int num;
    int i;
    
    stack_a = NULL;
	num = 0;
	i = 0;
    while(arr_of_num[i])
    {
        num = ft_atoi(arr_of_num[i]);
        if (i == 0)
        {
            stack_a = init_stack(num);
            if(!stack_a)
                return (NULL);
        }
        else
            stack_add_bottom(&stack_a, init_stack(num));
        i++;
    }
    return (stack_a);
}

int get_stack_size(t_stack *stack_a)
{
    int i;
    t_stack *tmp;

    tmp = stack_a;
    i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}