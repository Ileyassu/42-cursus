#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libraries/libraries.h"

typedef struct s_stack
{
    int value;
    struct s_stack *target;
    struct s_stack *next;
}   t_stack;

void print_error_exit(void);
char **error_check(int ac, char **av);
char	**free_double_array(char **s);
int	have_duplicates(char **av);
int is_arg_valid(char *av);
t_stack *init_stack(int num);
int is_sign(char c);
char *join_all(int ac, char **av);
int get_stack_size(t_stack *stack_a);
t_stack *add_to_stack(char **arr_of_num);
void free_list(t_stack *head);
int is_arr_sorted(char **arr_of_num);
int is_sorted(t_stack *stack_a);
void swap(t_stack **stack);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss (t_stack **stack_a, t_stack **stack_b);
void push(t_stack **stack_one, t_stack **stack_two);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_b, t_stack **stack_a);
void rotate(t_stack **stack);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void reverse_rotate(t_stack **stack);
void rrb(t_stack **stack_b);
void rra(t_stack **stack_a);
void sort(t_stack **stack_a, t_stack **b);
void sort_three(t_stack **stack);

#endif