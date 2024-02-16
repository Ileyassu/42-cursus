#include "../includes/so_long.h"

int	ft_key_hook(int keycode, t_mlx *mlx)
/* will cause the different actions of the valid key presses
** will cause you to window if you reached the exit */
{
	if (keycode == ESC)
		ft_exit(mlx, 1);
	else if (keycode == W){
		move_player(mlx, 'y', UP);}
	else if (keycode== A)
		move_player(mlx, 'x', LEFT);
	else if (keycode == S)
		move_player(mlx, 'y', DOWN);
	else if (keycode == D)
		move_player(mlx, 'x', RIGHT);
	if (mlx->map->tiles[mlx->p_y][mlx->p_x] == 'E')
	{
		if(mlx->count_drhm != mlx->drahm_in_map)
		{
			ft_printf("Salah ignoring you, collect more drahm\n");
			return (0);
		}
		// ft_printf("Player : \"Ara chi talyane lahafdk\"\n");
		// usleep(800000);
		// ft_printf("Salah : \"ch7al mne skara ?\"\n");
		// usleep(800000);
		// ft_printf("Player : \"joj\"\n");
		// usleep(800000);
		// ft_printf("Salah started making talyane for player.\n");
		// usleep(800000);
		// ft_printf("..\n");
		// usleep(800000);
		// ft_printf("...\n");
		// usleep(800000);
		// ft_printf("....\n");
		// usleep(800000);
		// ft_printf("talyane is ready.\n");
	 	ft_exit(mlx, 1);
	}
	return (0);
}