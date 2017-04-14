#include "fractol.h"

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
