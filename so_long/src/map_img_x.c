#include "../includes/so_long.h"

static void check_elements (t_mlx *mlx, int x, int y)
{
            if(mlx->map->tiles[y][x] == '0')
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
}

void map_img_x(t_mlx *mlx, int x, int y, int len)
{

     while(x < len)
        {
            if(ft_strlen(mlx->map->tiles[y]) <= x || mlx->map->tiles[y][x] == '1')
            {
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->background, x * 30 , y * 30 );
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->map->img, x * 30, y * 30 );
            }
            else if(mlx->map->tiles[y][x] == 'E')
            {
                mlx->exit_x = x;
                mlx->exit_y = y;
                mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->salah, x* 30 , y * 30 );
            }
            check_elements (mlx, x, y);
            x++;
        }
}