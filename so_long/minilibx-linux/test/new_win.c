


#include "mlx.h"


void *mlx;
void *window1;
void *window2;



int gere_mouse(int x,int y,int button,void*toto)
{
  printf("Mouse event - new window\n");
  mlx_destroy_window(mlx,window1);
  window1 = mlx_new_window(mlx,random()%500,random()%500,"new window");
  mlx_mouse_hook(window1,gere_mouse,0);
}


int main()
{
  srandom(time(0));
  mlx = mlx_init();
  window1 = mlx_new_window(mlx,300,300,"window1");
  window2 = mlx_new_window(mlx,600,600,"window2");
  mlx_mouse_hook(window1,gere_mouse,0);
  mlx_mouse_hook(window2,gere_mouse,0);
  mlx_loop(mlx);
}
