#include "../../includes/push_swap.h"

void set_target_node(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *roaming_a;
    t_stack *roaming_b;
    t_stack *target_node;
    long best_match_number;

    best_match_number = LONG_MIN;
    roaming_a = *stack_a;
    while (roaming_a != NULL)
    {
        roaming_b = *stack_b;
        while (roaming_b != NULL)
        {   
            if (roaming_a->value > roaming_b->value && roaming_b->value > best_match_number)
            {
                best_match_number = roaming_b->value;
                target_node = roaming_b;
            }
            roaming_b = roaming_b->next;
        }
        if (best_match_number == LONG_MIN)
            roaming_a->target = find_max_node(stack_b);
        else
            roaming_a->target = target_node;
        roaming_a = roaming_a->next;
    }
}

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

void set_cheapest(t_stack *stack)
{
	long			cheapest_value;
	t_stack         *cheapest_node;
    t_stack *tmp;

    tmp = stack;
    cheapest_node = NULL;
	if (!tmp)
		return;
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