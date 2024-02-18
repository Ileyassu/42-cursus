/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:11 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/18 15:05:23 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_arr(char **tiles, int height)
{
	int	i;

	i = 0;
	while (i <= height)
	{
		free(tiles[i++]);
	}
	free(tiles);
}

int	ft_exit(t_mlx *mlx, int i)
{
	if (mlx->map->tiles)
	{
		free_arr(mlx->map->tiles, mlx->height);
	}
	if (mlx->map)
		free(mlx->map);
	// if (mlx->img)
	// 	free(mlx->img);
	if (mlx->mlx && mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	exit(i);
}
