#include "../../includes/push_swap.h"

void sort_three(t_stack **stack)
{
    int a;
    int b;
    int c;

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
    {
        sa(stack);
        ra(stack);
    }
}