#include "../../includes/push_swap.h"

void move_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;

    cheapest_node = set_cheapest(stack_a);
    if (cheapest_node->above_median && cheapest_node->target->above_median)
        rotate_a_b(stack_a, stack_b, cheapest_node);
    else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
        reverse_rotate_a_b(stack_a, stack_b, cheapest_node);
    make_push(stack_a, cheapest_node, ra(stack_a), rra(stack_a));
    make_push(stack_a, cheapest_node->target_node, rb(stack_b), rrb(stack_b));
    pb(stack_b, stack_a);
}

void move_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    make_push(stack_a, (*stack_b)->target, ra(stack_a), rra(stack_a));
    pa(stack_b, stack_a);
}