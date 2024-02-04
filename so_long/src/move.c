#include "../includes/so_long.h"

void player_in_map(t_mlx *mlx)
{
    int x = 0;
    int y = 0;

    mlx->img->player_up = mlx_xpm_file_to_image(mlx->mlx, "./tiles/player/down.xpm", IMG_W, IMG_H);
    while(mlx->map->tiles[y])
    {
        while(mlx->map->tiles[y][x])
        {
            if(mlx->map->tiles[y][x] == 'P')
            {
                break;
            }
            x++;
        }
        y++;
    }
    mlx->p_x = y;
    mlx->p_x = x;
}

void move_player (t_mlx *mlx, int direction)
{
    int new_x = mlx->p_x;
    int new_y = mlx->p_y;
    void player_in_map(t_mlx *mlx);
    if (direction == 1) // Move up
    {
        new_y--;
    }
    else if (direction == 2) // Move down
    {
        new_y++;
    }
    else if (direction == 3) // Move left
    {
        new_x--;
    }
    else if (direction == 4) // Move right
    {
        new_x++;
    }

    // Check if the new position is within the map, not a wall, and not a border
    if (new_x >= 0 && new_x < mlx->map->width && new_y >= 0 && 
        new_y < mlx->map->height && mlx->map->tiles[new_y][new_x] != 'W'
        && mlx->map->tiles[new_y][new_x] != '1')
    {
        // Move player to the new position
        mlx->map->tiles[mlx->p_y][mlx->p_x] = '0'; // Empty the old position
        mlx->map->tiles[new_y][new_x] = 'P'; // Place the player at the new position
        mlx->p_x = new_x;
        mlx->p_y = new_y;
    }
}