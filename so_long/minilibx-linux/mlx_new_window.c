/*
** mlx_new_window.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 17:29:02 2000 Charlie Root
** Last update Thu Oct  4 15:44:43 2001 Charlie Root
*/


/*
** We do not use White/BlackPixel macro, TrueColor Visual make sure
** 0 is black & -1 is white
**
** With mlx_int_wait_first_expose, no flush is needed.
*/

#include	"mlx_int.h"


void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
{
	t_window_list				*new_window;
	XSetwindowAttributes	xswa;
	XGCValues				xgcv;

	xswa.background_pixel = 0;
	xswa.border_pixel = -1;
	xswa.colormap = xvar->cmap;
	/*
	xswa.event_mask = ButtonPressMask | ButtonReleaseMask | ExposureMask |
		KeyPressMask | KeyReleaseMask | StructureNotifyMask;
	*/
	/* xswa.event_mask = ExposureMask; */
	xswa.event_mask = 0xFFFFFF;	/* all events */
	if (!(new_window = malloc(sizeof(*new_window))))
		return ((void *)0);
	new_window->window = XCreatewindow(xvar->display,xvar->root,0,0,size_x,size_y,
					0,CopyFromParent,InputOutput,xvar->visual,
					CWEventMask|CWBackPixel|CWBorderPixel|
					CWColormap,&xswa);
	mlx_int_anti_resize_window(xvar,new_window->window,size_x,size_y);
	XStoreName(xvar->display,new_window->window,title);
	XSetWMProtocols(xvar->display, new_window->window, &(xvar->wm_delete_window), 1);
	xgcv.foreground = -1;
	xgcv.function = GXcopy;
	xgcv.plane_mask = AllPlanes;
	new_window->gc = XCreateGC(xvar->display,new_window->window,
				GCFunction|GCPlaneMask|GCForeground,&xgcv);
	new_window->next = xvar->window_list;
	xvar->window_list = new_window;
	/*
	new_window->mouse_hook = mlx_int_do_nothing;
	new_window->key_hook = mlx_int_do_nothing;
	new_window->expose_hook = mlx_int_do_nothing;
	*/
	bzero(&(new_window->hooks), sizeof(new_window->hooks));
	XMapRaised(xvar->display,new_window->window);
	mlx_int_wait_first_expose(xvar,new_window->window);
	return (new_window);
}
