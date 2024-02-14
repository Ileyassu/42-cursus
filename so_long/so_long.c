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

int main(int ac, char **av)
{
    if (!error_check(ac, av))
        return (0);
    t_mlx mlx;
    char *filename;
    mlx.map = malloc(sizeof(t_map));
    if (!mlx.map)
    {
        free(mlx.map);
        return (0);
    }
    mlx.img = malloc(sizeof(t_img));
    if (!mlx.img)
    {
        free(mlx.img);
        return (0);
    }
    mlx.map->tiles = NULL;
    filename = ft_strdup(av[1]);
    if (!filename)
    {
        free(filename);
        return (0);
    }
    extract_ber(&mlx, mlx.map, filename);
    free(filename);
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, mlx.width * 30, mlx.height * 30, "Road to salah moul 9hhwa");
    ft_action(&mlx);
    mlx_loop(mlx.mlx);
}