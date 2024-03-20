#include "../../includes/push_swap.h"

void sort(t_stack **stack_a, t_stack **stack_b)
{
    int arg_num;

    arg_num = get_stack_size(*stack_a);
    if (arg_num == 2)
        sa(stack_a);
    else if (arg_num == 3)
        sort_three(stack_a);
    else 
    {
        sort_stack(stack_a, stack_b);
    }
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;

    stack_size = get_stack_size(stack_a);
    if (stack_size > 3 && !is_sorted(stack_a))
        pb(stack_b, stack_a);
    if (stack_size > 3 && !is_sorted(stack_a))
        pb(stack_b, stack_a);
    while (stack_size > 3 && !is_sorted(stack_a))
    {
        fill_stack_b(stack_a, stack_b);
    }

}