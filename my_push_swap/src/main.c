/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:48:42 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/16 20:02:03 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **arr_of_num;

    (void) stack_a;
    (void) stack_b;

    if (ac < 2)
        return (0);
    arr_of_num = error_check(ac, av);
    if (!arr_of_num)
    {  
        printf("Error\n");
        return (0);
    }
    printf("Works\n");
    stack_a = add_to_stack(arr_of_num);
    free(arr_of_num);
    t_stack *tmp;
    tmp = stack_a;
    int size = 0;
    while(tmp)
    {
        ft_printf("%d ", tmp->value);
        tmp = tmp->next;
        size++;
    }
    printf("        size = %d\n", size);
    free(stack_a);
}