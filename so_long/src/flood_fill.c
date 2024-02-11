#include "../includes/so_long.h"

char **map_duplicate(t_mlx *mlx)
{
    int i = 0;
    char **duplicate;

    duplicate = NULL;
    duplicate = malloc(sizeof(char *) * (mlx->height + 1));
    while(mlx->map->tiles[i])
    {
        duplicate[i] = ft_strdup(mlx->map->tiles[i]);
        i++;
    }
    return duplicate;
}

void flood_fill(char **map, int x, int y, char old_char, char new_char)
{
    if (x < 0 || y < 0 || !map[x] || y >= ft_strlen(map[x]) || map[x][y] != old_char)
    {
        return;
    }

    map[x][y] = new_char;

    flood_fill(map, x + 1, y, old_char, new_char);
    flood_fill(map, x - 1, y, old_char, new_char);
    flood_fill(map, x, y + 1, old_char, new_char);
    flood_fill(map, x, y - 1, old_char, new_char);
}

// Function to check if the player can reach the exit
int canPlayerReachExit(char **duplicate, int playerX, int playerY, int exitX, int exitY)
{
    flood_fill(duplicate, playerX, playerY, '0', 'E');  // Assuming '5' is a new character for reachable cells
    return duplicate[exitX][exitY] == 'E';  // Check if the exit is marked with '5'
}