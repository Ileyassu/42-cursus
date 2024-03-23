#include "../../includes/push_swap.h"

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
}