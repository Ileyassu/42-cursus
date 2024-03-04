/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:19:17 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/27 21:18:58 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	struct_checker(t_mlx *mlx)
{
	if (!mlx->img->player_up || !mlx->img->player_left
		|| !mlx->img->player_right || !mlx->img->player_down
		|| !mlx->img->background || !mlx->img->salah
		|| !mlx->img->drhm || !mlx->map->img || !mlx->p_img)
	{
		destroy_objects(mlx);
		ft_printf("Invalid tile\n");
		ft_exit(mlx, 1);
		return (0);
	}
	return (1);
}

int	ft_put_objects(t_mlx *mlx)
{
	mlx->img->player_up = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/player/up.xpm", &mlx->map->width, &mlx->map->height);
	mlx->img->player_left = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/player/left.xpm", &mlx->map->width, &mlx->map->height);
	mlx->img->player_right = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/player/right.xpm", &mlx->map->width, &mlx->map->height);
	mlx->img->player_down = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/player/down.xpm", &mlx->map->width, &mlx->map->height);
	mlx->img->background = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/map_build/ground.xpm", &mlx->map->width,
			&mlx->map->height);
	mlx->img->salah = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/map_build/salah.xpm", &mlx->map->width, &mlx->map->height);
	mlx->img->drhm = mlx_xpm_file_to_image(mlx->mlx, "./tiles/coin/drhm.xpm",
			&mlx->map->width, &mlx->map->height);
	mlx->map->img = mlx_xpm_file_to_image(mlx->mlx,
			"./tiles/map_build/rock.xpm", &mlx->map->width, &mlx->map->height);
	mlx->p_img = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/down.xpm",
			&mlx->map->width, &mlx->map->height);
	if(struct_checker(mlx))
		return (0);
	return (1);
}