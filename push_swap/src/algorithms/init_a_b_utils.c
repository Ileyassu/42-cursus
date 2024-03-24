#include "../../includes/push_swap.h"

void current_index(t_stack **stack)
{
    int i;
    t_stack *tmp;
    int median;

    if (!stack)
        return;
    median = get_stack_size(*stack) / 2;
    i = 0;
    tmp = *stack;
    while (tmp)
    {
        tmp->index = i;
        if (tmp->index <= median)
            tmp->above_median = 1;
        else
            tmp->above_median = 0;
        tmp = tmp->next;
        ++i;
    }
}