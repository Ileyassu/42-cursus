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
#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1

# define ESC 53
# define W 119
# define A 97
# define S 115
# define D 100

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
    void *p_img;
    t_map *map;
    t_img *img;
}   t_mlx;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
void map_adder(t_mlx *mlx);
void extract_ber(t_mlx *mlx, t_map *map);
int	ft_key_hook(int keycode, t_mlx *mlx);
void	move_player(t_mlx *mlx, char pos, int dir);

#endif