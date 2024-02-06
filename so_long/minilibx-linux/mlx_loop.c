/*
** mlx_loop.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Wed Aug  2 18:58:11 2000 Charlie Root
** Last update Fri Sep 30 14:47:41 2005 Olivier Crouzet
*/


#include	"mlx_int.h"

extern int	(*(mlx_int_param_event[]))();

static int	window_count(t_xvar *xvar)
{
	int			i;
	t_window_list	*window;

	i = 0;
	window = xvar->window_list;
	while (window)
	{
		window = window->next;
		++i;
	}
	return (i);
}

int			mlx_loop_end(t_xvar *xvar)
{
	xvar->end_loop = 1;
	return (1);
}

int			mlx_loop(t_xvar *xvar)
{
	XEvent		ev;
	t_window_list	*window;

	mlx_int_set_window_event_mask(xvar);
	xvar->do_flush = 0;
	while (window_count(xvar) && !xvar->end_loop)
	{
		while (!xvar->end_loop && (!xvar->loop_hook || XPending(xvar->display)))
		{
			XNextEvent(xvar->display,&ev);
			window = xvar->window_list;
			while (window && (window->window!=ev.xany.window))
				window = window->next;

			if (window && ev.type == ClientMessage && ev.xclient.message_type == xvar->wm_protocols && ev.xclient.mlx.l[0] == xvar->wm_delete_window && window->hooks[DestroyNotify].hook)
				window->hooks[DestroyNotify].hook(window->hooks[DestroyNotify].param);
			if (window && ev.type < MLX_MAX_EVENT && window->hooks[ev.type].hook)
				mlx_int_param_event[ev.type](xvar, &ev, window);
		}
		XSync(xvar->display, False);
		if (xvar->loop_hook)
			xvar->loop_hook(xvar->loop_param);
	}
	return (0);
}
