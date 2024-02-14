#include "../includes/so_long.h"

static char	**ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
	return (NULL);
}

char **duplicate(t_mlx *mlx)
{
    char **duplicate;

    duplicate = malloc(sizeof(char *) * (mlx->height + 1));
    if (!duplicate)
        return (NULL);
    int i = 0;
    while (mlx->map->tiles[i] != NULL)
    {
        duplicate[i] = ft_strdup(mlx->map->tiles[i]);
        if (!duplicate[i])
        {
            ft_free_arr(duplicate, i);
            return (NULL);
        }
        i++;
    }
    duplicate[i] = NULL;
    return (duplicate);
}