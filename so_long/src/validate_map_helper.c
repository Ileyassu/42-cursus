/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:30:07 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 22:17:01 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_width_valid(char **tiles, int width, int height, int i)
{
	i = 0;
	while (i < height)
	{
		if (ft_strlen(tiles[i]) != width)
		{
			ft_printf("Invalid map\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < width)
	{
		if (tiles[0][i] != '1' || tiles[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (tiles[i][0] != '1' || tiles[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (i);
}

int	validate_map_helper(char **tiles, t_mlx *mlx, int i)
{
	if (!tiles)
	{
		free(tiles);
		ft_exit(mlx, 1);
	}
	i = 0;
	i = is_width_valid(tiles, mlx->width, mlx->height, i);
	if (i == 0)
	{
		ft_free_arr(tiles, mlx->height);
		return (0);
	}
	i = 0;
	if (!ft_count_elements(mlx->height, mlx->width, mlx, tiles))
	{
		ft_free_arr(tiles, mlx->height);
		return (0);
	}
	if (mlx->player_count != 1 || mlx->exit_count != 1)
	{
		ft_free_arr(tiles, mlx->height);
		return (0);
	}
	return (1);
}
