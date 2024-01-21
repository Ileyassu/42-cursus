#include "so_long.h"

int	key_hook(int keycode, t_data *mlx)
{
	printf("Keycode for %c is : %d\n", keycode, keycode);
    if(keycode == 100)
        mlx->player.x += 10;
    else if(keycode == 119)
        mlx->player.y -= 10;
    else if(keycode == 97)
        mlx->player.x -= 10;
    else if(keycode == 115)
        mlx->player.y += 10;
    mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player.img, mlx->player.x, mlx->player.y);
	return (0);
}

int	main(void)
{
    int map[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
    };
    
    t_data mlx;

    mlx.mlx = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx, 400, 600, "Hello world");
    mlx.player.img = mlx_xpm_file_to_image(mlx.mlx, "player.xpm", &mlx.player.x, &mlx.player.y);
	
    mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}
