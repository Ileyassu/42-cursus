/*
** mlx_expose_hook.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie Root
** Last update Fri Feb 23 17:07:42 2001 Charlie Root
*/


#include	"mlx_int.h"




int		mlx_expose_hook(t_window_list *window,int (*funct)(),void *param)
{
  window->hooks[Expose].hook = funct;
  window->hooks[Expose].param = param;
  window->hooks[Expose].mask = ExposureMask;
}
