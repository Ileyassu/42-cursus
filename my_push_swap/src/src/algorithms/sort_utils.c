#include "../../includes/push_swap.h"

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
