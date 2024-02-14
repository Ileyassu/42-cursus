#include "../includes/so_long.h"

int ft_exit(t_mlx *mlx, int i)
{
    // Free the allocated resources
    if (mlx->map->tiles)
        free(mlx->map->tiles);
    if (mlx->map)
        free(mlx->map);
    if (mlx->img)
        free(mlx->img);

    // Close the window and exit the program
    if (mlx->mlx && mlx->window) 
        mlx_destroy_window(mlx->mlx, mlx->window);
    //mlx_destroy_window(mlx->mlx, mlx->window);
    exit(i);
}