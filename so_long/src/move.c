#include "../includes/so_long.h"

static int step_counter;

static void	ft_player_move(t_mlx *mlx, char position, int direction)
{
    int old_x = 0;
    int old_y = 0;

    old_y = mlx->p_y * IMG_H;
    old_x = mlx->p_x * IMG_W;
    mlx_do_sync(mlx->mlx);

    if (position == 'y' && direction == UP)
        mlx->p_y -= 1;
    if (position == 'x' && direction == LEFT)
        mlx->p_x -= 1;
    if (position == 'y' && direction == DOWN)
        mlx->p_y += 1;
    if (position == 'x' && direction == RIGHT)
        mlx->p_x += 1;
    if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'E' && mlx->count_drhm != mlx->drahm_in_map)
	{
	    mlx_do_sync(mlx->mlx);
        mlx->p_x = old_x / IMG_W;
        mlx->p_y = old_y / IMG_H;
        return;
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
    ft_printf("You moved %d steps\n", step_counter++);
}

void check_if_drhm (t_mlx *mlx)
{
	if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'C')
	{
		mlx->count_drhm++;
        ft_printf("Solde : %ddh\n", mlx->count_drhm);
        ft_printf("You moved %d steps\n", step_counter++);
        mlx->map->tiles[mlx->p_y][mlx->p_x] = '0';
        if(mlx->count_drhm == mlx->drahm_in_map)
		{
			ft_printf("You collected enough drahm for a talyane 3nde salah\n");
		}
	}
}

void	move_player(t_mlx *mlx, char pos, int dir)
/* will check if a move is valid and move the player if valid */
{	
    if (pos == 'y' && dir == UP && mlx->p_y - 1 >= 0 && mlx->map->tiles[mlx->p_y - 1][mlx->p_x] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'x' && dir == LEFT && mlx->p_x - 1 >= 0 && mlx->map->tiles[mlx->p_y][mlx->p_x - 1] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'y' && dir == DOWN && mlx->p_y + 1 < mlx->map->height && mlx->map->tiles[mlx->p_y + 1][mlx->p_x] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
	else if (pos == 'x' && dir == RIGHT && mlx->p_x + 1 < mlx->map->width && mlx->map->tiles[mlx->p_y][mlx->p_x + 1] != '1')
	{
		ft_player_move(mlx, pos, dir);
		mlx_do_sync(mlx->mlx);
	}
    check_if_drhm (mlx);
}