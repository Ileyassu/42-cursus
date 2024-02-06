#include "mlx_int.h"

int		mlx_mouse_move(t_xvar *xvar, t_window_list *window, int x, int y)
{
	XWarpPointer(xvar->display, None, window->window, 0, 0, 0, 0, x, y);
	return (0);
}

int		mlx_mouse_hide(t_xvar *xvar, t_window_list *window)
{
	static char mlx[1] = {0};
	Cursor cursor;
	Pixmap blank;
	XColor dummy;

	blank = XCreateBitmapFrommlx(xvar->display, window->window, mlx, 1, 1);
	cursor = XCreatePixmapCursor(xvar->display, blank, blank, &dummy, &dummy, 0, 0);
	XDefineCursor(xvar->display, window->window, cursor);
	XFreePixmap(xvar->display, blank);
	XFreeCursor(xvar->display, cursor);
}

int		mlx_mouse_show(t_xvar *xvar, t_window_list *window)
{
	XUndefineCursor(xvar->display, window->window);
}

/*
** Queries the position of the mouse pointer relative to the origin of the
** specified window and saves it to the provided location.
**
** If the pointer is not on the same screen as the specified window, both
** window_x_return and window_y_return are set to zero and the function returns 0.
*/

int		mlx_mouse_get_pos(t_xvar *xvar, t_window_list *window, \
			int *window_x_return, int *window_y_return)
{
	window		root_return;
	window		child_return;
	int			root_x_return;
	int			root_y_return;
	unsigned	mask_return;

	return (XQueryPointer(xvar->display, window->window, \
		&root_return, &child_return, &root_x_return, &root_y_return, \
		window_x_return, window_y_return, &mask_return));
}
