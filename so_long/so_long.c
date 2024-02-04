#include "./includes/so_long.h"

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
    map_adder(&mlx);
    mlx_loop(mlx.mlx);
}