/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:52:17 by ilyas             #+#    #+#             */
/*   Updated: 2024/03/24 16:06:52 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && (ft_atoi(av[i]) == ft_atoi(av[j])))
				return (1);
			if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[j]) < INT_MIN)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_arg_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ' || av[i] == '\t')
			i++;
		if (av[i] == '\0')
			break ;
		if (is_sign(av[i]) && ft_isdigit(av[i + 1]))
			i++;
		else if (is_sign(av[i]) && !ft_isdigit(av[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

char	*join_all(int ac, char **av)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin(tmp, av[i]);
		if (!tmp)
			return (NULL);
		tmp = ft_strjoin(tmp, " ");
		if (!tmp)
			return (NULL);
		i++;
	}
	return (tmp);
}
