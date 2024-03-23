#include "../../includes/push_swap.h"

void swap(t_stack **stack)
{
    t_stack *tmp;
    if (*stack && (*stack)->next)
    {
        tmp = (*stack);
        (*stack) = (*stack)->next;
        tmp->next = (*stack)->next;
        (*stack)->next = tmp;
    }
}

void push(t_stack **stack_receiver, t_stack **donator)
{

    if (*donator)
    {
        t_stack *tmp;

        tmp = (*donator);
        (*donator) = (*donator)->next;
        tmp->next = (*stack_receiver);
        (*stack_receiver) = tmp;
    }
}

void rotate(t_stack **stack)
{
    if ((*stack) && (*stack)->next)
    {
        t_stack *first;
        t_stack *last;

        first = *stack;
        last = *stack;
        while (last->next)
            last = last->next;
        *stack = first->next;
        first->next = NULL;
        last->next = first;
    }
}

void reverse_rotate(t_stack **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stack *last = *stack;
        t_stack *prev = NULL;

        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *stack;
        *stack = last;
    }
}