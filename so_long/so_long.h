#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include "./mlx.h"
#include <stdio.h>

typedef struct s_player
{
    void *img;
    int x;
    int y;
}   t_player;

typedef struct s_data 
{
    void *mlx;
    void *mlx_win;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    t_player player;
}   t_data;

#endif