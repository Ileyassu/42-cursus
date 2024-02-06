#include "../includes/so_long.h"

static void	ft_player_move(t_mlx *mlx, char position, int direction)
{
    int old_x = mlx->p_x * IMG_W;
    int old_y = mlx->p_y * IMG_H;

    mlx_do_sync(mlx->mlx);
    if (position == 'y' && direction == UP)
    {
        mlx->p_y -= 1;
    }
    if (position == 'x' && direction == LEFT)
    {
        mlx->p_x -= 1;
    }
    if (position == 'y' && direction == DOWN)
    {
        mlx->p_y += 1;
    }
    if (position == 'x' && direction == RIGHT)
    {
        mlx->p_x += 1;
    }

    // Draw the background at the old position
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, old_x, old_y);

    // Draw the player at the new position
    if (position == 'y' && direction == UP)
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_up, mlx->p_x * IMG_W, mlx->p_y * IMG_H);
    if (position == 'x' && direction == LEFT)
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_left, mlx->p_x * IMG_W, mlx->p_y * IMG_H);
    if (position == 'y' && direction == DOWN)
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_down, mlx->p_x * IMG_W, mlx->p_y * IMG_H);
    if (position == 'x' && direction == RIGHT)
        mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->player_right, mlx->p_x * IMG_W, mlx->p_y * IMG_H);
}

void	move_player(t_mlx *mlx, char pos, int dir)
/* will check if a move is valid and move the player if valid */
{
	if (pos == 'y' && dir == UP && mlx->map->tiles[mlx->p_y - 1][mlx->p_x] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'x' && dir == LEFT && mlx->map->tiles[mlx->p_y][mlx->p_x - 1] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'y' && dir == DOWN && mlx->map->tiles[mlx->p_y + 1][mlx->p_x] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'x' && dir == RIGHT && mlx->map->tiles[mlx->p_y][mlx->p_x + 1] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	//mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, mlx->p_x, mlx->p_y);
	//ft_player_move(mlx, pos, dir);
	// if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'C')
	// 	ft_collect(mlx, pos, dir);
	//printf("You moved %d times.\n", ++mlx->counter);
}