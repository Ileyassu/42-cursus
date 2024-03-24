/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:48:42 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/24 16:09:13 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arr_of_num;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	arr_of_num = error_check(ac, av);
	if (!arr_of_num)
		print_error_exit();
	if (is_arr_sorted(arr_of_num))
	{
		free_double_array(arr_of_num);
		return (0);
	}
	stack_a = add_to_stack(arr_of_num);
	if (stack_a == NULL)
		print_error_exit();
	sort(&stack_a, &stack_b);
	free_double_array(arr_of_num);
	free_list(stack_a);
	system("leaks push_swap\n");
}
