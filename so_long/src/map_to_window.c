#include "../includes/so_long.h"

static void put_objects(t_mlx *mlx)
{
    mlx->img->player_up = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/up.xpm", &mlx->map->width, &mlx->map->height);
    mlx->img->player_left = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/left.xpm", &mlx->map->width, &mlx->map->height);
    mlx->img->player_right = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/right.xpm", &mlx->map->width, &mlx->map->height);
    mlx->img->player_down = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/down.xpm", &mlx->map->width, &mlx->map->height);
    mlx->img->background = mlx_xpm_file_to_image(mlx->mlx, "./tiles/map_build/ground.xpm", &mlx->map->width, &mlx->map->height);
    mlx->img->salah = mlx_xpm_file_to_image(mlx->mlx, "./tiles/map_build/salah.xpm", &mlx->map->width, &mlx->map->height);
    mlx->img->drhm = mlx_xpm_file_to_image(mlx->mlx, "./tiles/coin/drhm.xpm", &mlx->map->width, &mlx->map->height);
    mlx->map->img = mlx_xpm_file_to_image(mlx->mlx, "./tiles/map_build/rock.xpm", &mlx->map->width, &mlx->map->height);
    mlx->p_img = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/down.xpm", &mlx->map->width, &mlx->map->height);
}

static int MaxMlx(char **map)
{

    int tmp = -1;
    int i = 0;
    while(map && map[i])
    {
        if (ft_strlen(map[i]) > tmp)
            tmp = ft_strlen(map[i]);
        i++;
    }
    return (tmp);
}

void map_adder(t_mlx *mlx)
{
    int x = 0;
    int y = 0;
    mlx->img = malloc(sizeof(t_img));
    mlx->p_x = IMG_W;
    mlx->p_y = IMG_H;
    put_objects(mlx);
    int len = MaxMlx(mlx->map->tiles);
    mlx->count_drhm = 0;
    mlx->drahm_in_map = 0;
    while(mlx->map->tiles[y])
    {
        x = 0;
        while(x < len)
        {
            if(ft_strlen(mlx->map->tiles[y]) <= x || mlx->map->tiles[y][x] == '1')
            {
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, x * 30 , y * 30 );
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map->img, x * 30, y * 30 );
            }
            else if(mlx->map->tiles[y][x] == '0')
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, x* 30 , y * 30 );
            else if(mlx->map->tiles[y][x] == 'P')
            {
                mlx->p_x = x;
                mlx->p_y = y;
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->p_img, x* 30 , y * 30 );
            }
            else if(mlx->map->tiles[y][x] == 'C')
            {
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->drhm, x* 30 , y * 30 );
                mlx->drahm_in_map++;
            }
            else if(mlx->map->tiles[y][x] == 'E')
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->salah, x* 30 , y * 30 );
            x++;
        }
        y++;
    }
}