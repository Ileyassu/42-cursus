/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:52:55 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/16 22:48:55 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_fd_error(t_mlx *mlx, int fd)
{
	if (fd < 0)
	{
		ft_printf("Error, couldn't find your map\n");
		ft_exit(mlx, 1);
		return (0);
	}
	return (1);
}

char	*array_extractor(t_mlx *mlx, char *path)
{
	char	*arr;
	char	*tmp;
	int		fd;

	arr = NULL;
	fd = open(path, O_RDONLY);
	if (!check_fd_error(mlx, fd))
		return (NULL);
	mlx->map->tiles = NULL;
	tmp = get_next_line(fd);
	while ((tmp != NULL))
	{
		if (!tmp)
			return (NULL);
		arr = ft_strjoin(arr, tmp);
		if (!arr)
			return (NULL);
		free(tmp);
		mlx->height++;
		tmp = get_next_line(fd);
	}
	close(fd);
	return (arr);
}

static void	is_map_valid(t_mlx *mlx)
{
	if (!validate_map(mlx))
	{
		ft_printf("map is not valid\n");
		ft_exit(mlx, 1);
	}
}

void	extract_ber(t_mlx *mlx, t_map *map, char *filename)
{
	char	*arr;
	char	*path;

	path = ft_strdup("./map/");
	if_error_free(path, mlx);
	path = ft_strjoin(path, filename);
	if_error_free(path, mlx);
	arr = NULL;
	mlx->height = 0;
	mlx->width = 0;
	arr = array_extractor(mlx, path);
	if_error_free(arr, mlx);
	free(path);
	mlx->map->tiles = ft_split(arr, '\n');
	if (!mlx->map->tiles)
		ft_exit(mlx, 1);
	free(arr);
	mlx->width = ft_strlen(map->tiles[0]);
	is_map_valid(mlx);
}
