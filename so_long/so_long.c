#include "./includes/so_long.h"

static int error_check(int ac, char **av)
{
    if (ac != 2)
    {
        ft_printf("Error\n");
        return (0);
    }
    if (!ft_strstr(av[1], ".ber"))
    {
        ft_printf("Error\n");
        return (0);
    }
    return (1);
}

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
    if (mlx->mlx && mlx->window) 
    {
        mlx_destroy_window(mlx->mlx, mlx->window);
        printf("tset\n");
    }
    //mlx_destroy_window(mlx->mlx, mlx->window);
    exit(0);
}

int main(int ac, char **av)
{
    if (!error_check(ac, av))
        return (0);
    t_mlx mlx;
    char *filename;
    mlx.map = malloc(sizeof(t_map));
    mlx.img = malloc(sizeof(t_img));
    mlx.map->tiles = NULL;
    filename = ft_strdup(av[1]);
    extract_ber(&mlx, mlx.map, filename);
    printf("tset\n");

    free(filename);
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, mlx.width * 30, mlx.height * 30, "Road to salah moul 9hhwa");
    ft_action(&mlx);
    mlx_loop(mlx.mlx);
}