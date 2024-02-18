/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:24 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/18 14:35:14 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_at_new_position(t_mlx *mlx, char position, int direction)
{
	if (position == 'y' && direction == UP)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_up,
			mlx->p_x * IMG_W, mlx->p_y * IMG_H);
	if (position == 'x' && direction == LEFT)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_left,
			mlx->p_x * IMG_W, mlx->p_y * IMG_H);
	if (position == 'y' && direction == DOWN)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_down,
			mlx->p_x * IMG_W, mlx->p_y * IMG_H);
	if (position == 'x' && direction == RIGHT)
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_right,
			mlx->p_x * IMG_W, mlx->p_y * IMG_H);
	ft_printf("You moved %d steps\n", ++mlx->step_counter);
}

static void	ft_player_move(t_mlx *mlx, char position, int direction)
{
	int	old_x;
	int	old_y;

	old_x = 0;
	old_y = 0;
	old_y = mlx->p_y * IMG_H;
	old_x = mlx->p_x * IMG_W;
	if (position == 'y' && direction == UP)
		mlx->p_y -= 1;
	if (position == 'x' && direction == LEFT)
		mlx->p_x -= 1;
	if (position == 'y' && direction == DOWN)
		mlx->p_y += 1;
	if (position == 'x' && direction == RIGHT)
		mlx->p_x += 1;
	if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'E'
		&& mlx->count_drhm != mlx->drahm_in_map)
	{
		mlx->p_x = old_x / IMG_W;
		mlx->p_y = old_y / IMG_H;
		return ;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, old_x,
		old_y);
	draw_at_new_position(mlx, position, direction);
}

void	check_if_drhm(t_mlx *mlx)
{
	if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'C')
	{
		mlx->count_drhm++;
		ft_printf("Solde : %ddh\n", mlx->count_drhm);
		mlx->map->tiles[mlx->p_y][mlx->p_x] = '0';
		if (mlx->count_drhm == mlx->drahm_in_map)
		{
			ft_printf("You collected enough drahm for a talyane 3nde salah\n");
		}
	}
}

void	move_player(t_mlx *mlx, char pos, int dir)
{
	if (pos == 'y' && dir == UP && mlx->p_y - 1 >= 0 && mlx->map->tiles[mlx->p_y
			- 1][mlx->p_x] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'x' && dir == LEFT && mlx->p_x - 1 >= 0
		&& mlx->map->tiles[mlx->p_y][mlx->p_x - 1] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'y' && dir == DOWN && mlx->p_y + 1 < mlx->height
		&& mlx->map->tiles[mlx->p_y + 1][mlx->p_x] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'x' && dir == RIGHT && mlx->p_x + 1 < mlx->width
		&& mlx->map->tiles[mlx->p_y][mlx->p_x + 1] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	check_if_drhm(mlx);
}
