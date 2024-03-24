/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:20:10 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/03/24 15:23:00 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	filter_one_helper(char *av, int *count_digit)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ' && av[i] != '\t' && !is_sign(av[i])
			&& !ft_isdigit(av[i]))
			return (0);
		if (ft_isdigit(av[i]))
			*count_digit = 1;
		i++;
	}
	return (1);
}

int	filter_one(int ac, char **av)
{
	int	i;
	int	count_digit;

	count_digit = 0;
	i = 1;
	while (i < ac)
	{
		if (is_arg_empty(av[i]))
			return (0);
		count_digit = 0;
		if (!av[i][0])
			return (0);
		if (!filter_one_helper(av[i], &count_digit))
			return (0);
		i++;
	}
	return (1);
}
