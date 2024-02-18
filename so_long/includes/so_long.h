/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:03:29 by ibenaiss          #+#    #+#             */
/*   Updated: 2024/02/18 14:34:35 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../getnextline/get_next_line.h"
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
	void	*drhm;
	void	*background;
	void	*salah;
}			t_img;

typedef struct s_map
{
	void	*img;
	int		width;
	int		height;
	char	**tiles;
}			t_map;

typedef struct s_mlx
{
	void	*mlx;
	int		height;
	int		width;
	void	*window;
	int		coins_collected;
	int		exit_y;
	int		exit_x;
	int		step_counter;
	int		exit_reachable;
	int		p_x;
	int		p_y;
	void	*p_img;
	int		total_coins;
	int		drahm_in_map;
	int		count_drhm;
	int		player_count;
	int		exit_count;
	int		coin_count;
	t_map	*map;
	t_img	*img;
}			t_mlx;

void		*ft_memcpy(void *dest, const void *src, size_t n);
char		**ft_split(const char *s, char c);
int			ft_exit(t_mlx *mlx, int i);
void		map_adder(t_mlx *mlx);
void		*ft_memset(void *str, int c, size_t n);
void		extract_ber(t_mlx *mlx, t_map *map, char *av);
int			ft_key_hook(int keycode, t_mlx *mlx);
void		move_player(t_mlx *mlx, char pos, int dir);
int			max_mlx(char **map);
char		**duplicate(t_mlx *mlx);
int			ft_count_elements(int height, int width, t_mlx *mlx, char **tiles);
char		*ft_strstr(const char *big, const char *little);
void		free_two_d_array(int **array, int height);
void		map_img_x(t_mlx *mlx, int x, int y, int len);
int			**create_double_array(int height, int width);
void		ft_put_objects(t_mlx *mlx);
char		**ft_free_arr(char **tiles, int height);
void		if_error_free(char *str, t_mlx *mlx);
int			validate_map_helper(char **tiles, t_mlx *mlx, int i);
void		flood_fill(t_mlx *mlx, int x, int y, int **visited);
int			validate_map(t_mlx *mlx);

#endif
