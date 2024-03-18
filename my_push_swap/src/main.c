/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:48:42 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/17 15:53:21 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void print_error()
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **arr_of_num;
    
    (void) stack_b;
    if (ac < 2)
        return (0);
    arr_of_num = error_check(ac, av);
    if (!arr_of_num)
        print_error();
    stack_a = add_to_stack(arr_of_num);
    free_double_array(arr_of_num);
    free_list(stack_a);
}