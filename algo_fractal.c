#include "fractol.h"

void	ft_pixel_put_image(t_env *list, int x, int y, int true)
{
	int tmp;

	tmp = (x + (y * WIDTH));
	if (y >= 0 && x >= 0 && true == 1)
		*(((int*)list->adi) + tmp) = 0xff23ff + (0x01101100 * list->md.i*255/list->md.iteration_max);
	else if (true == 0)
		*(((int*)list->adi) + tmp) = 0x000000;

}
void	ft_init(t_env *list)
{
	list->md.x1 = -2;
	list->md.x2 = 0.5;
	list->md.y1 = -1.25;
	list->md.y2 = 1.25;
	list->md.image_x = WIDTH;
	list->md.image_y = HEIGHT;
	list->md.iteration_max = 600;
}

int		ft_mandelbrot(t_env *list)
{

	list->md.zoom_x = list->md.image_x/(list->md.x2 - list->md.x1);
	list->md.zoom_y = list->md.image_y/(list->md.y2 - list->md.y1);
	list->md.x = 0;
	while (list->md.x < list->md.image_x)
	{
		list->md.y = 0;
    	while (list->md.y < list->md.image_y)
		{
			list->md.c_r = list->md.x / list->md.zoom_x + list->md.x1;
			list->md.c_i = list->md.y / list->md.zoom_y + list->md.y1;
			list->md.z_r = 0;
			list->md.z_i = 0;
			list->md.i = 0;
        	while (list->md.z_r * list->md.z_r + list->md.z_i * list->md.z_i < 4 && list->md.i < list->md.iteration_max)
			{
				list->md.tmp = list->md.z_r;
 	        	list->md.z_r = list->md.z_r * list->md.z_r - list->md.z_i * list->md.z_i + list->md.c_r;
        	    list->md.z_i = 2 * list->md.z_i* list->md.tmp + list->md.c_i;
           	 	list->md.i++;
			}
            if (list->md.i != list->md.iteration_max)
				ft_pixel_put_image(list, list->md.x, list->md.y, 1);
			else
				ft_pixel_put_image(list, list->md.x, list->md.y, 0);
			list->md.y++;
    	}
		list->md.x++;
	}
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	return (0);
}

int ft_choose_fractal(t_env *list)
{
	/*if (list->i == 1)
		ft_julia();*/
	if (list->i == 2)
	{
		ft_init(list);
		ft_mandelbrot(list);
	}
	/*else if (list->i == 3)
		ft_cesaro();*/
	return (0);
}

int		ft_draw_pix(t_env *list)
{
	list->mlx = mlx_init();
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "mlx_42");
	list->img_ptr = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	list->adi = mlx_get_data_addr(list->img_ptr, &list->bpp,
	&list->size_line, &list->endian);
	ft_choose_fractal(list);
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	mlx_key_hook(list->win, ft_key_funct, list);
	mlx_mouse_hook(list->win, ft_mouse_funct, list);
	mlx_loop_hook(list->mlx, &ft_mandelbrot, list);
	mlx_loop(list->mlx);
	return (0);
}
