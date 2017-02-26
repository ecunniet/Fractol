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

void	ft_mandelbrot(t_env *list)
{
// on définit la zone que l'on dessine. Ici, la fractale en entière
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
	double	image_x = 400;
	double	image_y = 370;
	double	iteration_max = 50;
// on calcule la taille de l'image :
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
