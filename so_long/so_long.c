/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:51:15 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/27 21:02:02 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static int	error_check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error, wrong number of arguments\n");
		return (0);
	}
	if (!ft_strstr(av[1], ".ber"))
	{
		ft_printf("Error, file format is not supported\n");
		return (0);
	}
	return (1);
}

static int	ft_action(t_mlx *mlx)
{
	map_adder(mlx);
	mlx_hook(mlx->window, 17, 1L << 2, ft_exit, mlx);
	mlx_key_hook(mlx->window, ft_key_hook, mlx);
	return (1);
}

static int	initializer(t_mlx *mlx)
{
	mlx->step_counter = 0;
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
	{
		free(mlx->map);
		return (0);
	}
	mlx->img = malloc(sizeof(t_img));
	if (!mlx->img)
	{
		free(mlx->img);
		return (0);
	}
	mlx->map->tiles = NULL;
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	char	*filename;

	if (!error_check(ac, av))
		return (0);
	if (!initializer(&mlx))
		return (0);
	mlx.map->tiles = NULL;
	filename = ft_strdup(av[1]);
	if (!filename)
	{
		free(filename);
		return (0);
	}
	extract_ber(&mlx, mlx.map, filename);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.width * 30, mlx.height * 30,
			"Road to salah moul 9hhwa");
	//free(filename);
	free(mlx.img);
	ft_action(&mlx);
	mlx_loop(mlx.mlx);
}
