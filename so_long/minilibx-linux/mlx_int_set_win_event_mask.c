/*
** mlx_int_set_window_event_mask.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie Root
** Last update Fri Feb 23 17:07:42 2001 Charlie Root
*/


#include	"mlx_int.h"




int	mlx_int_set_window_event_mask(t_xvar *xvar)
{
  t_window_list	*window;
  int		mask;
  int		i;
  XSetwindowAttributes	xwa;

  window = xvar->window_list;
  while (window)
    {
      xwa.event_mask = 0;
      i = MLX_MAX_EVENT;
      while (i--)
	xwa.event_mask |= window->hooks[i].mask;
      XChangewindowAttributes(xvar->display, window->window, CWEventMask, &xwa);
      window = window->next;
    }
}
