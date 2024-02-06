/*
** mlx_int_param_event.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Wed Oct  6 13:14:52 2004 Olivier Crouzet
*/

#include	"mlx_int.h"

int	mlx_int_param_undef()
{
}

int	mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  window->hooks[KeyPress].hook(XkbKeycodeToKeysym(xvar->display,
					       ev->xkey.keycode, 0, 0),
			    window->hooks[KeyPress].param);
}

int	mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  window->hooks[KeyRelease].hook(XkbKeycodeToKeysym(xvar->display,
						 ev->xkey.keycode, 0, 0),
			      window->hooks[KeyRelease].param);
}

int	mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  window->hooks[ButtonPress].hook(ev->xbutton.button,ev->xbutton.x,ev->xbutton.y,
			       window->hooks[ButtonPress].param);
}

int	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  window->hooks[ButtonRelease].hook(ev->xbutton.button,
				 ev->xbutton.x, ev->xbutton.y,
				 window->hooks[ButtonRelease].param);
}

int	mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  window->hooks[MotionNotify].hook(ev->xbutton.x,ev->xbutton.y,
				window->hooks[MotionNotify].param);
}

int	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  if (!ev->xexpose.count)
    window->hooks[Expose].hook(window->hooks[Expose].param);
}


int	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_window_list *window)
{
  window->hooks[ev->type].hook(window->hooks[ev->type].param);
}

int	(*(mlx_int_param_event[]))() =
{
  mlx_int_param_undef,   /* 0 */
  mlx_int_param_undef,
  mlx_int_param_KeyPress,
  mlx_int_param_KeyRelease,  /* 3 */
  mlx_int_param_ButtonPress,
  mlx_int_param_ButtonRelease,
  mlx_int_param_MotionNotify,  /* 6 */
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_Expose,   /* 12 */
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic,
  mlx_int_param_generic
};
