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

t_stack *find_max_node(t_stack **stack)
{
    t_stack *tmp;
    long max;

    if (!stack)
        return (NULL);
    tmp = *stack;
    max = LONG_MIN;
    while (tmp)
    {
        if (max < tmp->value)
            max = tmp->value;
        tmp = tmp->next;
    }
	return (tmp);
}

t_stack *find_min_node(t_stack **stack)
{
    t_stack *tmp;
    long min;

    if (!stack)
        return (NULL);
    tmp = *stack;
    min = LONG_MAX;
    while (tmp)
    {
        if (min > tmp->value)
            min = tmp->value;
        tmp = tmp->next;
    }
	return (tmp);
}

void rotate_a_b(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
    while(*stack_a != cheapest_node && (*stack_a)->target != cheapest_node->target)
        rr(stack_a, stack_b);
    current_index(stack_a);
    current_index(stack_b);
}

void reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
    while(*stack_a != cheapest_node && (*stack_a)->target != cheapest_node->target)
        rrr(stack_a, stack_b);
    current_index(stack_a);
    current_index(stack_b);
}

void make_push(t_stack **stack, t_stack *cheapest_node, void(*rotate_move)(t_stack**), void(*reverse_rotate_move)(t_stack**))
{
    while(*stack != cheapest_node)
    {
        if (cheapest_node->above_median == 1)
            rotate_move(stack);
        else
            reverse_rotate_move(stack);
    }
}

void minimum_to_top(t_stack **stack_a)
{
    t_stack *min_node;

    min_node = find_min_node(stack_a);
    while((*stack_a)->value != min_node->value)
    {
        if (min_node->above_median)
            ra(stack_a);
        else
            rra(stack_a);
    }
}