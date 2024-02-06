#include "../includes/so_long.h"

static void	ft_player_move(t_mlx *mlx, char position, int direction)
/* will put the correct orientation of the player on the screen */
{
	if (position == 'y' && direction == UP)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_up,
			(mlx->p_x * IMG_W), (mlx->p_y * IMG_H));
	}
	if (position == 'x' && direction == LEFT)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_left,
			(mlx->p_x * IMG_W), (mlx->p_y * IMG_H));
	}
	if (position == 'y' && direction == DOWN)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_down,
			(mlx->p_x * IMG_W), (mlx->p_y * IMG_H));
	}
	if (position == 'x' && direction == RIGHT)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_right,
			(mlx->p_x * IMG_W), (mlx->p_y * IMG_H));
	}
}

void	move_player(t_mlx *mlx, char pos, int dir)
/* will check if a move is valid and move the player if valid */
{
	printf("wsslte hhna, p_x = %dp_y )= %d\n", mlx->p_x, mlx->p_y);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background,
		mlx->p_x, mlx->p_y);
	if (pos == 'y' && mlx->map->tiles[mlx->p_y][mlx->p_x] != '1'
		&& (mlx->map->tiles[mlx->p_y + 1][mlx->p_x] != 'E'))
		mlx->p_y = mlx->p_y + 1;
	else if (pos == 'x' && mlx->map->tiles[mlx->p_y][mlx->p_x + 1 * dir] != '1'
		&& (mlx->map->tiles[mlx->p_y][mlx->p_x + 1] != 'E'))
		mlx->p_x = mlx->p_x + 1;
	else if (pos == 'y' && mlx->map->tiles[mlx->p_y + 1][mlx->p_x] == 'E')
		printf("Collect all diamonds before leaving\n");
	else if (pos == 'x' && mlx->map->tiles[mlx->p_y][mlx->p_x + 1] == 'E')
		printf("Collect all diamonds before leaving\n");
	ft_player_move(mlx, pos, dir);
	// if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'C')
	// 	ft_collect(mlx, pos, dir);
	mlx_do_sync(mlx->mlx);
	//printf("You moved %d times.\n", ++mlx->counter);
}