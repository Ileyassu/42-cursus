/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:20:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:20:18 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libraries.h"

typedef struct s_stack
{
	struct s_stack	*target;
	int				value;
	int				index;
	int				cheapest;
	int				above_median;
	int				push_cost;
	struct s_stack	*next;
}					t_stack;

void				print_error_exit(void);
char				**error_check(int ac, char **av);
char				**free_double_array(char **s);
int					have_duplicates(char **av);
int					filter_one(int ac, char **av);
int					is_arg_empty(char *str);
int					is_arg_valid(char *av);
t_stack				*init_stack(int num);
int					is_sign(char c);
char				*join_all(int ac, char **av);
int					get_stack_size(t_stack *stack_a);
t_stack				*add_to_stack(char **arr_of_num);
void				free_list(t_stack *head);
int					is_arr_sorted(char **arr_of_num);
int					is_sorted(t_stack *stack_a);
void				current_index(t_stack **stack);
void				set_target_node(t_stack **stack_a, t_stack **stack_b);
void				cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
void				init_stacks(t_stack **stack_a, t_stack **stack_b);
void				init_nodes_b(t_stack **a, t_stack **b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
void				sort(t_stack **stack_a, t_stack **stack_b);
void				move_to_stack_b(t_stack **stack_a, t_stack **stack_b);
void				move_to_stack_a(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_max_node(t_stack **stack);
t_stack				*find_min_node(t_stack *stack);
void				set_target_b(t_stack *a, t_stack *b);
void				rotate_a_b(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest_node);
void				reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest_node);
void				make_push(t_stack **stack, t_stack *top_node,
						char stack_name);
void				minimum_to_top(t_stack **stack_a);
void				set_cheapest(t_stack *stack);
void				calculate_cost(t_stack *stack_a, t_stack *stack_b);
void				swap(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				push(t_stack **stack_one, t_stack **stack_two);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate(t_stack **stack);
void				rrb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack);

#endif