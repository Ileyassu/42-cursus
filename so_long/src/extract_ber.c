#include "../includes/so_long.h"

char **duplicate(t_mlx *mlx)
{
    char **duplicate;

    duplicate = malloc(sizeof(char *) * (mlx->height + 1));
    int i = 0;
    while (mlx->map->tiles[i] != NULL)
    {
        duplicate[i] = ft_strdup(mlx->map->tiles[i]);
        i++;
    }
    duplicate[i] = NULL;
    return (duplicate);
}

int validate_map(t_mlx *mlx) {
    int width = mlx->width;
    int height = mlx->height;
    char **tiles;
    
    //fix segfault on tiles
    tiles = duplicate(mlx);
    int player_count = 0;
    int exit_count = 0;
    int coin_count = 0;
    int i = 0, j;

    while(i < height)
    {
        printf("hhna : %s\n", "tiles[i]");
        if (ft_strlen(tiles[i]) != width)
        {
            ft_printf("Invalid map\n");
            return (0);
        }
        i++;
    }

    // Check if the map is surrounded by walls
    i = 0;
    while (i < width) {
        if (tiles[0][i] != '1' || tiles[height-1][i] != '1')
            return 0;
        i++;
    }

    i = 0;
    while (i < height) {
        if (tiles[i][0] != '1' || tiles[i][width-1] != '1')
            return 0;
        i++;
    }

    // Count the number of 'P', 'E', and 'C'
    i = 0;
    while (i < height) {
        j = 0;
        while (j < width) {
            if (tiles[i][j] == 'P') {
                player_count++;
                mlx->p_y = i;
                mlx->p_x = j;
            } else if (tiles[i][j] == 'E') {
                exit_count++;
                mlx->exit_y = i;
                mlx->exit_x = j;
            } else if (tiles[i][j] == 'C') {
                coin_count++;
            }
            j++;
        }
        i++;
    }
    // Check if there is exactly one player and one exit
    if (player_count != 1 || exit_count != 1)
    {
        return 0;
    }
    // Check if the player can reach all coins and the exit
    int **visited = create_2D_array(height, width);
    mlx->total_coins = coin_count;
    mlx->coins_collected = 0;
    mlx->exit_reachable = 0;
    flood_fill(mlx, mlx->p_x, mlx->p_y, visited); //somehow makydkhlch l floodfill
    i = 0;
    j = 0;
    if (mlx->coins_collected < mlx->total_coins || !mlx->exit_reachable) {
        free_2D_array(visited, mlx->height);
        return 0; // Map is not valid
    }
    for (int i = 0; i < mlx->height; i++) {
    for (int j = 0; j < mlx->width; j++) {
        printf("%d", visited[i][j]);
    }
    printf("\n");
}
    free_2D_array(visited, height);
    
    //return (1);
    return (mlx->coins_collected == mlx->total_coins) && (mlx->exit_reachable);
}

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
    if (!validate_map(mlx))
    {
        ft_printf("ft_exit\n");
        ft_exit(mlx);
    }
}