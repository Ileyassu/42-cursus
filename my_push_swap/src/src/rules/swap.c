#include "../../includes/push_swap.h"

void sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");
}

void ss (t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("ss\n");
}