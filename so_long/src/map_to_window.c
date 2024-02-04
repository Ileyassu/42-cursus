#include "../includes/so_long.h"

// void put_background(t_mlx *mlx)
// {
//     int		y;
// 	int		x;

// 	y = 0;
// 	while (y < mlx->height)
// 	{
// 		x = 0;
// 		while (x < mlx->width)
// 		{
// 			mlx_put_image_to_window(mlx->mlx, mlx->window,
// 				mlx->img->background, x, y);
// 			x += IMG_W;
// 		}
// 		y += IMG_H;
// 	}
// }

int MaxMlx(char **map)
{

    int tmp = -1;
    int i = 0;
    while(map && map[i])
    {
        if (ft_strlen(map[i]) > tmp)
        {
            tmp = ft_strlen(map[i]);
        }
        i++;
    }
    return (tmp);
}

void map_adder(t_mlx *mlx)
{
    int x = 0;
    int y = 0;
    mlx->img = malloc(sizeof(t_img));
    mlx->img->background = mlx_xpm_file_to_image(mlx->mlx, "./tiles/map_build/ground.xpm", &mlx->map->width, &mlx->map->height);
    void *tree_img = mlx_xpm_file_to_image(mlx->mlx, "./tiles/map_build/rock.xpm", &mlx->map->width, &mlx->map->height);
    int len = MaxMlx(mlx->map->tiles);
    while(mlx->map->tiles[y])
    {
        x = 0;
        while(x < len)
        {
            if(ft_strlen(mlx->map->tiles[y]) <= x || mlx->map->tiles[y][x] == '1')
            {
                mlx->map->img = tree_img;
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, x* 30 , y * 30 );
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map->img, x * 30, y * 30 );
            }
            else if(mlx->map->tiles[y][x] == '0')
            {
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, x* 30 , y * 30 );
            }

            x++;
        }
        y++;
    }
}