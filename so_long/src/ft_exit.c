#include "../includes/so_long.h"

void free_arr(char **tiles, int height)
{
    int i;

    i = 0;
    while(i <= height)
    {
        free(tiles[i++]);
    }
    free(tiles);
}
int ft_exit(t_mlx *mlx, int i)
{
    // Free the allocated resources
    printf("height = %d\n", mlx->height);
    int y = 0;
    while(mlx->map->tiles[y])
    {
        printf("mlx->map = %p index = %d array = %p string = %s address = %p\n", mlx->map, y, mlx->map->tiles, mlx->map->tiles[y], mlx->map->tiles[y]);
        y++;
    }
    // printf("height = %p\n", mlx->map);
    // printf("height = %p\n", mlx->img);
    if (mlx->map->tiles)
    {
        free_arr(mlx->map->tiles, mlx->height);
        system("leaks so_long");
    }
    if (mlx->map)
    {
        free(mlx->map);
    }
    if (mlx->img)
    {
        free(mlx->img);
    }

    // Close the window and exit the program
    if (mlx->mlx && mlx->window) 
        mlx_destroy_window(mlx->mlx, mlx->window);
    //mlx_destroy_window(mlx->mlx, mlx->window);
    exit(i);
}