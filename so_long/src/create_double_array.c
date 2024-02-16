/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_double_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:52:49 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 17:07:11 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	**create_double_array(int height, int width)
{
	int	**array;
	int	i;

	array = malloc(height * sizeof(int *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		array[i] = malloc(width * sizeof(int));
		if (array[i] == NULL)
		{
			while (i >= 0)
			{
				free(array[i]);
				i--;
			}
			free(array);
			return (NULL);
		}
		ft_memset(array[i], 0, width * sizeof(int));
		i++;
	}
	return (array);
}

void	free_two_d_array(int **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
