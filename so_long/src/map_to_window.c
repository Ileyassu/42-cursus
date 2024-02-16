/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:21 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 18:45:56 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	max_mlx(char **map)
{
	int	tmp;
	int	i;

	tmp = -1;
	i = 0;
	while (map && map[i])
	{
		if (ft_strlen(map[i]) > tmp)
			tmp = ft_strlen(map[i]);
		i++;
	}
	return (tmp);
}

void	objects_check_add(t_mlx *mlx, int x, int y)
{
	if (mlx->map->tiles[y][x] == 'P')
	{
		mlx->p_x = x;
		mlx->p_y = y;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->p_img, x * 30, y
			* 30);
	}
	else if (mlx->map->tiles[y][x] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->drhm, x * 30, y
			* 30);
		mlx->drahm_in_map++;
	}
	else if (mlx->map->tiles[y][x] == 'E')
	{
		mlx->exit_x = x;
		mlx->exit_y = y;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->salah, x * 30,
			y * 30);
	}
}

void	map_x_adder(t_mlx *mlx, int x, int y, int len)
{
	while (x < len)
	{
		if (ft_strlen(mlx->map->tiles[y]) <= x || mlx->map->tiles[y][x] == '1')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background,
				x * 30, y * 30);
			mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map->img, x
				* 30, y * 30);
		}
		else if (mlx->map->tiles[y][x] == '0')
			mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background,
				x * 30, y * 30);
		objects_check_add(mlx, x, y);
		x++;
	}
}

void	map_adder(t_mlx *mlx)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	mlx->img = malloc(sizeof(t_img));
	mlx->p_x = IMG_W;
	mlx->p_y = IMG_H;
	ft_put_objects(mlx);
	len = max_mlx(mlx->map->tiles);
	mlx->count_drhm = 0;
	mlx->drahm_in_map = 0;
	while (mlx->map->tiles[y])
	{
		x = 0;
		map_x_adder(mlx, x, y, len);
		y++;
	}
}
