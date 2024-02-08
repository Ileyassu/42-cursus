#include "../includes/so_long.h"

void extract_ber(t_mlx *mlx, t_map *map, char *filename) //next give it argc and argv
{
    char *arr;
    char *tmp;
    char *path;
    
    path = ft_strdup("./map/");
    path = ft_strjoin(path, filename);
    if(!path)
    {
        free(path);
        return;
    }
    arr = NULL;
    mlx->height = 0;
    mlx->width = 0;

    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error, couldn't find your map\n");
        exit(0);
        return;
    }
    mlx->map->tiles = NULL;
    while((tmp = get_next_line(fd)))
    {
        arr = ft_strjoin(arr, tmp);
        if(!arr)
            return;
        mlx->height++;
    }
    free(tmp);
    free(path);
    close(fd);
    mlx->map->tiles = ft_split(arr, '\n');
    mlx->width = ft_strlen(map->tiles[0]); 
}