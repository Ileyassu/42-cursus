#include "../../includes/push_swap.h"

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