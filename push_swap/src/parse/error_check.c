/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:48:32 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/25 00:59:10 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	error_check_helper(char **av, int ac, int *i)
{
	if (!filter_one(ac, av))
		return (0);
	while (*i < ac)
	{
		if (!is_arg_valid(av[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}

char	**error_check(int ac, char **av)
{
	int		i;
	char	*tmp;
	char	**arr_of_numbers;

	tmp = NULL;
	i = 1;
	if (!error_check_helper(av, ac, &i))
		return (NULL);
	tmp = join_all(ac, av);
	if (!tmp)
		return (0);
	arr_of_numbers = ft_split(tmp, ' ');
	if (!arr_of_numbers)
	{
		free(tmp);
		return (NULL);
	}
	if (have_duplicates(arr_of_numbers))
	{
		free_double_array(arr_of_numbers);
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (arr_of_numbers);
}
