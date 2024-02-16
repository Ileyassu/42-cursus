/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:27 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 22:39:22 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	too_much_things_going_on(t_mlx *mlx, int **visited)
{
	mlx->total_coins = mlx->coin_count;
	mlx->coins_collected = 0;
	mlx->exit_reachable = 0;
	flood_fill(mlx, mlx->p_x, mlx->p_y, visited);
	if (mlx->coins_collected < mlx->total_coins || !mlx->exit_reachable)
		return (0);
	return (1);
}

int	validate_map(t_mlx *mlx)
{
	char	**tiles;
	int		i;
	int		**visited;

	i = 0;
	tiles = duplicate(mlx);
	if (!validate_map_helper(tiles, mlx, i))
	{
		return (0);
	}
	visited = create_double_array(mlx->height, mlx->width);
	if (!too_much_things_going_on(mlx, visited))
	{
		ft_free_arr(tiles, mlx->height);
		free_two_d_array(visited, mlx->height);
		return (0);
	}
	ft_free_arr(tiles, mlx->height);
	free_two_d_array(visited, mlx->height);
	return ((mlx->coins_collected == mlx->total_coins)
		&& (mlx->exit_reachable));
}
