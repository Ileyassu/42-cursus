#include "../../includes/push_swap.h"

void init_stacks(t_stack **stack_a, t_stack **stack_b)
{
    ((*stack_a)->target = NULL);
    ((*stack_b)->target = NULL);
    current_index(stack_a);
    current_index(stack_b);
    set_target_node(stack_a, stack_b);
    calculate_cost(*stack_a, *stack_b);
    set_cheapest(*stack_a);
}

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long			best_match_index;

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


void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;

    stack_size = get_stack_size(*stack_a);
    if (stack_size-- > 3 && !is_sorted(*stack_a))
        pb(stack_b, stack_a);
    if (stack_size-- > 3 && !is_sorted(*stack_a))
        pb(stack_b, stack_a);
    while (stack_size-- > 3 && !is_sorted(*stack_a))
    {
        init_stacks(stack_a, stack_b);
        move_to_stack_b(stack_a, stack_b);
    }
    sort_three(stack_a);
    while(*stack_b)
    {

        init_nodes_b(stack_a, stack_b);
        move_to_stack_a(stack_a, stack_b);
    }

    current_index(stack_a);
    minimum_to_top(stack_a);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
    int arg_num;

    arg_num = get_stack_size(*stack_a);
    if (arg_num == 2)
        sa(stack_a);
    else if (arg_num == 3)
        sort_three(stack_a);
    sort_stack(stack_a, stack_b);
}