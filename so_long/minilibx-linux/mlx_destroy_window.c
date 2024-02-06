/*
** mlx_destroy_window.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Tue Mar 12 10:25:15 2002 Charlie Root
** Last update Tue May 15 16:46:08 2007 Olivier Crouzet
*/


#include	"mlx_int.h"


int	mlx_destroy_window(t_xvar *xvar,t_window_list *window)
{
  t_window_list	*w;
  t_window_list	*prev;
  t_window_list	first;

  first.next = xvar->window_list;
  prev = &first;
  w = prev->next;
  while (w)
    {
      if (w==window)
	prev->next = w->next;
      else
	prev = w;
      w = w->next;
    }
  xvar->window_list = first.next;
  XDestroywindow(xvar->display,window->window);
  XFreeGC(xvar->display,window->gc);
  free(window);
  if (xvar->do_flush)
    XFlush(xvar->display);
}
