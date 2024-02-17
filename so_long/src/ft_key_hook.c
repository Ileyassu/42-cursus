/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:42 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/17 12:04:18 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		ft_exit(mlx, 1);
	else if (keycode == W)
	{
		move_player(mlx, 'y', UP);
	}
	else if (keycode == A)
		move_player(mlx, 'x', LEFT);
	else if (keycode == S)
		move_player(mlx, 'y', DOWN);
	else if (keycode == D)
		move_player(mlx, 'x', RIGHT);
	if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'E')
	{
		ft_exit(mlx, 0);
	}
	return (0);
}
