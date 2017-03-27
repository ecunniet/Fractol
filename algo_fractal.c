//Mandelbrot lol§
#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 1000
#define HEIGHT 850
#define CASE1 18

void	ft_pixel_put_image(t_env *list, int x, int y)
{
	int tmp;

	tmp = (x + (y * WIDTH));
	if (y >= 0 && x >= 0)
		*(((int*)list->adi) + tmp) = 0xff23ff;
}

int	ft_mandelbrot(t_env *list)
{
// on définit la zone que l'on dessine. Ici, la fractale en entière
	list->md.x1 = -2.1;
	list->md.x2 = 0.6;
	list->md.y1 = -1.2;
	list->md.y2 = 1.2;
	list->md.image_x = 1000;
	list->md.image_y = 750;
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
            if (list->md.i == list->md.iteration_max)
				ft_pixel_put_image(list, list->md.x, list->md.y);
			list->md.y++;
    	}
		list->md.x++;
	}
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	return (0);
}

int			ft_key_funct(int keycode, t_env *list)
{
	printf("keycode = %d\n", keycode);
	list->zoom = (keycode == 67) ? (list->zoom + 0.2) : list->zoom;
	list->zoom = (keycode == 75 && list->zoom > 0.3) ? (list->zoom - 0.2)
	: list->zoom;
		if (keycode == CASE1)
	{
		list->md.iteration_max = (list->md.iteration_max > 10) ? list->md.iteration_max - 10 : list->md.iteration_max;
		list->md.iteration_max = (list->md.iteration_max <= 10 && list->md.iteration_max > 0) ? list->md.iteration_max - 1 : list->md.iteration_max;
		printf("iteration max = %f\n", list->md.iteration_max);
	}
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int			ft_mouse_funct(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
/*	if (button == 1)
	{
	// pour recentrer faire une difference avec x et y vis a vis du centre comme ca toute la fractal est decaller
		list->center_x = x;
		list->center_y = y;
	}
	if (button == 2)
	{
	//pour tout reset c'est ici
		list->b_x = 0;
		list->b_y = 0;
		list->b_z = 0;
		list->angle_x = 15;
		list->angle_y = 25;
		list->angle_z = 0;
		list->center_x = -1;
		list->center_y = -1;
		list->zoom = 1;
		list->rainbow = 0;
	}*/
/*	if (button == 4)
	{
	}
	if (button == 5)
	{
	}*/
	return (0);
}

int		ft_draw_pix(t_env *list)
{
	list->mlx = mlx_init();
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "mlx_42");
	list->img_ptr = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	list->adi = mlx_get_data_addr(list->img_ptr, &list->bpp,
	&list->size_line, &list->endian);
	/*if (list->i == 1)
		ft_julia();*/
	if (list->i == 2)
	{
		list->md.iteration_max = 600;
		ft_mandelbrot(list);
	}
	/*else if (list->i == 3)
		ft_cesaro();*/
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	mlx_key_hook(list->win, ft_key_funct, list);
	mlx_mouse_hook(list->win, ft_mouse_funct, list);
	mlx_loop_hook(list->mlx, &ft_mandelbrot, list);
	mlx_loop(list->mlx);
	return (0);
}

void	ft_verif(char *fract, t_env *list)
{
	list->i = (ft_strcmp(fract, "Julia") == 0) ? 1 : 0;
	list->i = (ft_strcmp(fract, "Mandelbrot") == 0
	&& list->i == 0) ? 2 : list->i;
	list->i = (ft_strcmp(fract, "Cesaro") == 0
	&& list->i == 0) ? 3 : list->i;
	if (list->i == 0)
		ft_error(1, fract);
}

int		main(int argc, char **argv)
{
	t_env	list;

	if (argc == 2)
	{
		ft_verif(argv[1], &list);
		ft_draw_pix(&list);
	}
	else
		ft_error(0, 0);
	return (0);
}
