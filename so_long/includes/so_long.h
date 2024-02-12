#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../printf/ft_printf.h"
# include "../mlx/mlx.h"
# include "../getnextline/get_next_line.h"

# define BUFFER_SIZE 3
# define IMG_H 30
# define IMG_W 30
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
    void    *drhm;
	void	*background;
    void	*salah;
}				t_img;

typedef struct s_map
{
    void *img;
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
    int coins_collected; //i need this one to check the map
    int exit_y;
    int exit_x;
    int exit_reachable; //this one to check exit
    int p_x;
    int p_y;
    void *p_img;
    int total_coins;
    int drahm_in_map;
    int count_drhm;
    t_map *map;
    t_img *img;
}   t_mlx;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
int ft_exit(t_mlx *mlx);
void map_adder(t_mlx *mlx);
void	*ft_memset(void *str, int c, size_t n);
void extract_ber(t_mlx *mlx, t_map *map, char *av);
int	ft_key_hook(int keycode, t_mlx *mlx);
int ft_exit(t_mlx *mlx);
void	move_player(t_mlx *mlx, char pos, int dir);
int MaxMlx(char **map);
char **map_duplicate(t_mlx *mlx);
char	*ft_strstr(const char *big, const char *little);
void free_2D_array(int **array, int height);
int **create_2D_array(int height, int width);
void flood_fill(t_mlx *mlx, int x, int y, int **visited);


#endif