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
    free(arr);
    mlx->width = ft_strlen(map->tiles[0]);
}

// int map_checker(t_mlx *mlx)
// {
//     int checker;
//     int x;
//     int y = 0;
//     int len = MaxMlx(mlx->map->tiles);
//     char **duplicate;

//     duplicate = map_duplicate(mlx);
//     while(mlx->map->tiles[y])
//     {
//         x = 0;
//         while(x < len)
//         {
//             if(duplicate[y][x] == 'E')
//             {
//                 mlx->exit_y = y;
//                 mlx->exit_x = x;
//             }
//             x++;
//         }
//         y++;
//     }
//     checker = canPlayerReachExit(duplicate, mlx->p_x, mlx->p_y, mlx->exit_x, mlx->exit_y);
//     //should add more code here
// }