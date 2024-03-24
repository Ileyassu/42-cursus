#include "../../includes/push_swap.h"

void init_stacks(t_stack **stack_a, t_stack **stack_b)
{
    ((*stack_a)->target = NULL);
    ((*stack_b)->target = NULL);
    current_index(stack_a);
    current_index(stack_b);
    set_target_node(stack_a, stack_b);
    calculate_cost(*stack_a, *stack_b);
    set_cheapest(*stack_a);
    printf("stack->value = %d\n", (*stack_a)->value);
    //printf("trdy\n");
}
void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b); //add this
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int stack_size;

    stack_size = get_stack_size(*stack_a);
    if (stack_size-- > 3 && !is_sorted(*stack_a))
        pb(stack_b, stack_a);
    if (stack_size-- > 3 && !is_sorted(*stack_a))
        pb(stack_b, stack_a);
    while (stack_size-- > 3 && !is_sorted(*stack_a))
    {
        init_stacks(stack_a, stack_b);
        move_to_stack_b(stack_a, stack_b);
    }
    sort_three(stack_a);
    while(*stack_b)
    {
        init_nodes_b(*stack_a, *stack_b);
        move_to_stack_a(stack_a, stack_b);
        
        printf("9rbte\n");
        printf("tesooot\n");
    }
    current_index(stack_a);
    minimum_to_top(stack_a);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
    int arg_num;

    arg_num = get_stack_size(*stack_a);
    if (arg_num == 2)
        sa(stack_a);
    else if (arg_num == 3)
        sort_three(stack_a);
    //t_stack *tmp = *stack_a;
    sort_stack(stack_a, stack_b);
    // while(tmp)
    // {
    //     sort_stack(stack_a, stack_b);
    //     tmp = tmp->next;
    // }
}