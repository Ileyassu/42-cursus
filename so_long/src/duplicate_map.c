/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:52:51 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/17 11:44:48 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**duplicate(t_mlx *mlx)
{
	char	**duplicate;
	int		i;

	duplicate = malloc(sizeof(char *) * (mlx->height + 1));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (mlx->map->tiles[i] != NULL)
	{
		duplicate[i] = ft_strdup(mlx->map->tiles[i]);
		if (!duplicate[i])
		{
			ft_free_arr(duplicate, i);
			return (NULL);
		}
		i++;
	}
	duplicate[i] = NULL;
	return (duplicate);
}
