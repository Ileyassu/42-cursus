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