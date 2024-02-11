#include "../includes/so_long.h"

int **create_2D_array(int height, int width) {
    int **array = malloc(height * sizeof(int *));
    if (array == NULL) {
        return NULL;
    }

    int i = 0;
    while (i < height) {
        array[i] = malloc(width * sizeof(int));
        if (array[i] == NULL) {
            while (i >= 0) {
                free(array[i]);
                i--;
            }
            free(array);
            return NULL;
        }
        ft_memset(array[i], 0, width * sizeof(int)); // Initialize all elements to 0
        i++;
    }

    return array;
}

void free_2D_array(int **array, int height) {
    int i = 0;
    while (i < height) {
        free(array[i]);
        i++;
    }
    free(array);
}

// Flood fill function
void flood_fill(t_mlx *mlx, int x, int y, int **visited) {
    // Base cases
    if (x < 0 || x >= mlx->map->width || y < 0 || y >= mlx->map->height) {
        return; // Out of bounds
    }
    if (visited[y][x] || mlx->map->tiles[y][x] == '1') {
        return; // Already visited or is a wall
    }

    // Mark as visited
    visited[y][x] = 1;

    // Process the tile
    if (mlx->map->tiles[y][x] == 'C') {
        mlx->coins_collected++;
    } else if (mlx->map->tiles[y][x] == 'E') {
        mlx->exit_reachable = 1;
    }

    // Recur for all directions
    flood_fill(mlx, x-1, y, visited); // Left
    flood_fill(mlx, x+1, y, visited); // Right
    flood_fill(mlx, x, y-1, visited); // Up
    flood_fill(mlx, x, y+1, visited); // Down
}