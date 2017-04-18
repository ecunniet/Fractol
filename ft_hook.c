#include "fractol.h"

int			ft_key_funct(int keycode, t_env *list)
{
	// printf("keycode = %d\n", keycode);
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
	// printf("button = %d et x = %d et y = %d\n", button, x, y);
/*	if (button == 1)
	{
	// pour recentrer faire une difference avec x et y vis a vis du centre comme ca toute la fractal est decaller
		list->center_x = x;
		list->center_y = y;
	}*/
	if (button == 2)
		ft_init(list);
	if (button == 4)
	{
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 	
	/*
		list->md.x1 = (x > 500) ? list->md.x1 * 0.5: list->md.x1;
		list->md.x2 = (x < 500) ? list->md.x2 * 0.5: list->md.x2;
		list->md.y1 = (y > 375) ? list->md.y1 * 0.5: list->md.y1;
		list->md.y2 = (y < 375) ? list->md.y2 * 0.5: list->md.y2;
		// printf("x1 = %f, x2 = %f, y1 = %f, y2 = %f\n", list->md.x1, list->md.x2, list->md.y1, list->md.y2);
	*/
	}
	if (button == 5)
	{

	/*	
		list->md.x1 = (x > 500) ? list->md.x1 * 2: list->md.x1;
		list->md.x2 = (x < 500) ? list->md.x2 * 2: list->md.x2;
		list->md.y1 = (y > 375) ? list->md.y1 * 2: list->md.y1;
		list->md.y2 = (y < 375) ? list->md.y2 * 2: list->md.y2;
		// printf("x1 = %f, x2 = %f, y1 = %f, y2 = %f\n", list->md.x1, list->md.x2, list->md.y1, list->md.y2);
	*/	
	}
	return (0);
}
