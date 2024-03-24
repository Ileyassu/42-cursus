#include "../../includes/push_swap.h"

t_stack	*get_cheapest(t_stack *stack) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void move_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest_node;

    cheapest_node = get_cheapest((*stack_a));
    printf("cheapest node value= %d\n", cheapest_node->value);
    //tmp = (*stack_a);
    t_stack *tmp = (*stack_b);
    while (tmp)
    {
        printf("stack_b->value = %d\n", tmp->value);
        tmp = tmp->next;
    }
    printf("---------\n");
    if (cheapest_node->above_median == 1 && cheapest_node->target->above_median == 1)
    {
        rotate_a_b(stack_a, stack_b, cheapest_node);
        t_stack *tmp1 = (*stack_b);
        while (tmp1)
        {
            printf("stack_bb->value = %d\n", tmp1->value);
            tmp1 = tmp1->next;
        }
    }
    else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
    {
        reverse_rotate_a_b(stack_a, stack_b, cheapest_node);
    }
    printf("(*stack_b)->target->value = %d\n",(*stack_b)->target->value);
    make_push(stack_a, cheapest_node, 'a');
    make_push(stack_b, cheapest_node->target, 'b');
    printf("test tani\n");
    pb(stack_b, stack_a);
    // tmp = (*stack_a);
    // while (tmp)
    // {
    //     printf("stack_a->value = %d\n", tmp->value);
    //     tmp = tmp->next;
    // }
}

void move_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    make_push(stack_a, (*stack_b)->target, 'a');
    pa(stack_a, stack_b);
}