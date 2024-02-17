/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:00 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/17 14:02:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_mlx *mlx, int x, int y, int **visited)
{
	if (visited[y][x] || mlx->map->tiles[y][x] == '1')
	{
		return ;
	}
	if (mlx->map->tiles[y][x] == 'E')
	{
		mlx->exit_reachable = 1;
		return ;
	}
	visited[y][x] = 1;
	if (mlx->map->tiles[y][x] == 'C')
	{
		mlx->coins_collected++;
	}
	flood_fill(mlx, x - 1, y, visited);
	flood_fill(mlx, x + 1, y, visited);
	flood_fill(mlx, x, y - 1, visited);
	flood_fill(mlx, x, y + 1, visited);
}
