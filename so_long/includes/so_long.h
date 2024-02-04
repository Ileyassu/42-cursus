#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include "../getnextline/get_next_line.h"

#define BUFFER_SIZE 3
#define IMG_H 30
#define IMG_W 30
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
}				t_img;

typedef struct s_map
{
    void *img;
    void *tree;
    int width;
    int height;
    char **tiles;
}   t_map;

typedef struct s_mlx 
{
    void *mlx;
    int height;
    int width;
    void *window;
    int p_x;
    int p_y;
    t_map *map;
    t_img *img;
}   t_mlx;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
void map_adder(t_mlx *mlx);
void extract_ber(t_mlx *mlx, t_map *map);
char	*ft_strchr(const char *str, int c);

#endif