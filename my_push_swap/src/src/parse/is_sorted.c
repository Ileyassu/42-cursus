#include "../../includes/push_swap.h"

int is_arr_sorted(char **arr_of_num)
{
    int i;
    int j;

    j = 1;
    i = 0;
    while (arr_of_num[i] && arr_of_num[j])
    {
        if (ft_atoi(arr_of_num[i]) > ft_atoi(arr_of_num[j]))
            return(0);
        j++;
        i++;
    }
    return (1);
}

int is_sorted(t_stack *stack_a)
{
    int i;

    i = 0;
    i = stack_a->value;
    while (stack_a)
    {
        if (stack_a->value < i)
            return (0);
        i = stack_a->value;
        stack_a = stack_a->next;
    }
    return (0);
}