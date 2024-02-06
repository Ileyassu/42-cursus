#include "./includes/so_long.h"

static int	ft_action(t_mlx *mlx)
/* checks for keyboard or mouse input */
{
    map_adder(mlx);
	mlx_hook(mlx->window, 17, 1L << 2, ft_exit, mlx);
	mlx_key_hook(mlx->window, ft_key_hook, mlx);
	return (0);
}

int ft_exit(t_mlx *mlx)
{
    // Free the allocated resources
    if (mlx->map) {
        free(mlx->map);
        mlx->map = NULL;
    }
    if (mlx->img) {
        free(mlx->img);
        mlx->img = NULL;
    }

    // Close the window and exit the program
    mlx_destroy_window(mlx->mlx, mlx->window);
    exit(0);
}

int main()
{
    t_mlx mlx;
    mlx.map = malloc(sizeof(t_map));
    mlx.img = malloc(sizeof(t_img));
    mlx.map->tiles = NULL;
    extract_ber(&mlx, mlx.map);    
    printf("%d\n",mlx.height);
    printf("width = %s\n", mlx.map->tiles[0]);
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, mlx.width * 30, mlx.height * 30, "Test");
    ft_action(&mlx);
    mlx_loop(mlx.mlx);
}