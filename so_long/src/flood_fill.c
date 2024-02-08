#include "../includes/so_long.h"

char **map_duplicate(t_mlx *mlx)
{
    int i = 0;
    char **duplicate;

    duplicate = NULL;
    duplicate = malloc(sizeof(char *) * mlx->height + 1);
    while(mlx->map->tiles[i])
    {
        duplicate[i] = ft_strdup(mlx->map->tiles[i]);
        i++;
    }
    return duplicate;
}