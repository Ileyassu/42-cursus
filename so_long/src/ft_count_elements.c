/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:07 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 22:52:53 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	g_spoter(char **tiles, int i, int j, t_mlx *mlx)
{
	if (tiles[i][j] == 'P')
	{
		mlx->player_count++;
		mlx->p_y = i;
		mlx->p_x = j;
	}
	else if (tiles[i][j] == 'E')
	{
		mlx->exit_count++;
		mlx->exit_y = i;
		mlx->exit_x = j;
	}
	else if (tiles[i][j] == 'C')
		mlx->coin_count++;
	else if (tiles[i][j] != '0' && tiles[i][j] != '1')
	{
		ft_printf("Invalid character in map\n");
		return (0);
	}
	return (1);
}

int	ft_count_elements(int height, int width, t_mlx *mlx, char **tiles)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (!g_spoter(tiles, i, j, mlx))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
