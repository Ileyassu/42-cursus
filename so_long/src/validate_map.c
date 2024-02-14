#include "../includes/so_long.h"

static char	**ft_free_arr(char **tiles, int height)
{
    int i = height;
	while (i--)
		free(tiles[i]);
	free(tiles);
	return (NULL);
}
static int is_width_valid (char **tiles, int width, int height)
{
    int i;

    i = 0;
    while(i < height)
    {
        if (ft_strlen(tiles[i]) != width)
        {
            ft_printf("Invalid map\n");
            return (0);
        }
        i++;
    }
    i = 0;
    while (i < width) {
        if (tiles[0][i] != '1' || tiles[height-1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < height) {
        if (tiles[i][0] != '1' || tiles[i][width-1] != '1')
            return (0);
        i++;
    }
    return (i);
}

int too_much_things_going_on(t_mlx *mlx, int **visited)
{
    mlx->total_coins = mlx->coin_count;
    mlx->coins_collected = 0;
    mlx->exit_reachable = 0;
    flood_fill(mlx, mlx->p_x, mlx->p_y, visited); //somehow makydkhlch l floodfill
    if (mlx->coins_collected < mlx->total_coins || !mlx->exit_reachable) 
        return 0; // Map is not valid
    return (1);
}
int validate_map(t_mlx *mlx) 
{
    char **tiles;
    int i;
    int **visited;

    tiles = duplicate(mlx);
    if (!tiles)
    {
        free(tiles);
        ft_exit(mlx, 1);
    }
    i = is_width_valid(tiles, mlx->width, mlx->height);
    if (i == 0)
    {
        ft_free_arr(tiles, mlx->height);
        return (0);
    }
    i = 0;
    if (!ft_count_elements (mlx->height, mlx->width, mlx, tiles))
    {
        ft_free_arr(tiles, mlx->height);
        return (0);
    }
    if (mlx->player_count != 1 || mlx->exit_count != 1)
    {
        ft_free_arr(tiles, mlx->height);
        return 0;
    }
    visited = create_2D_array(mlx->height, mlx->width);// Check if the player can reach all coins and the exit
    if (!too_much_things_going_on(mlx, visited))
    {
        ft_free_arr(tiles, mlx->height);
        free_2D_array(visited, mlx->height);
        return (0);
    }
    ft_free_arr(tiles, mlx->height);
    free_2D_array(visited, mlx->height);
    return (mlx->coins_collected == mlx->total_coins) && (mlx->exit_reachable);
}