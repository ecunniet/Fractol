//Mandelbrot
#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 400
#define HEIGHT 370

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
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
	double	image_x = 400;
	double	image_y = 370;
	double	iteration_max = 500;
	double	zoom_x = image_x/(x2 - x1);
	double	zoom_y = image_y/(y2 - y1);
	double	x = 0;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	double tmp;
	
	while (x < image_x)
	{
		double	y = 0;
    		while (y < image_y)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
        		while (z_r*z_r + z_i*z_i < 4 && i < iteration_max)
			{
				tmp = z_r;
 	        		z_r = z_r*z_r - z_i*z_i + c_r;
        	    		z_i = 2*z_i*tmp + c_i;
           	 		i++;
			}
            		if (i == iteration_max)
				ft_pixel_put_image(list, x, y);
			y++;
    		}
		x++;
	}
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	return (0);
}

int			ft_key_funct(int keycode, t_env *list)
{
	list->zoom = (keycode == 67) ? (list->zoom + 0.2) : list->zoom;
	list->zoom = (keycode == 75 && list->zoom > 0.3) ? (list->zoom - 0.2)
	: list->zoom;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int			ft_mouse_funct(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	if (button == 1)
	{
		list->center_x = x;
		list->center_y = y;
	}
	if (button == 2)
	{
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
	}
	return (0);
}

int		ft_draw_pix(t_env *list)
{
	list->mlx = mlx_init();
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "mlx_42");
	list->img_ptr = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	list->adi = mlx_get_data_addr(list->img_ptr, &list->bpp,
	&list->size_line, &list->endian);
	if (list->i == 2)
		ft_mandelbrot(list);
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
