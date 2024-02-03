#include "../includes/so_long.h"

void extract_ber(t_mlx *mlx, t_map *map) //next give it argc and argv
{
    char *arr;
    char *tmp;
    arr = NULL;
    mlx->height = 0;
    mlx->width = 0;
    int fd = open("./map/map.ber", O_RDONLY);
    mlx->map->tiles = NULL;
    while((tmp = get_next_line(fd)))
    {
        arr = ft_strjoin(arr, tmp);
        if(!arr)
            return;
        mlx->height++;
    }
    free(tmp);
    mlx->map->tiles = ft_split(arr, '\n');
    printf("width = %s\n", map->tiles[0]);
    mlx->width = ft_strlen(map->tiles[0]); 
}