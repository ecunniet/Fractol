/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:54:53 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/19 16:30:45 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change_fractal(t_env *list, int keycode)
{
	int		tmp;

	tmp = list->i;
	list->i = (keycode == ONE) ? 1 : list->i;
	list->i = (keycode == TWO) ? 2 : list->i;
	list->i = (keycode == THREE) ? 3 : list->i;
	if (list->i != tmp)
		ft_init(list);
}

int			ft_key_funct(int keycode, t_env *list)
{
	printf("keycode = %d\n", keycode);
	list->md.i_max = (keycode == I && list->md.i_max < 500) ?
	list->md.i_max + 10 : list->md.i_max;
	list->md.i_max = (keycode == O && list->md.i_max >= 10) ?
	list->md.i_max - 10 : list->md.i_max;
	list->md.zoom = (keycode == MORE) ? list->md.zoom *
	pow(1.001, FPS) : list->md.zoom;
	list->md.zoom = (keycode == LESS) ? list->md.zoom /
	pow(1.001, FPS) : list->md.zoom;
	list->md.moveY = (keycode == UP) ? list->md.moveY - 0.0003 * FPS
	/ list->md.zoom : list->md.moveY;
	list->md.moveY = (keycode == DOWN) ? list->md.moveY + 0.0003 * FPS
	/ list->md.zoom : list->md.moveY;
	list->md.moveX = (keycode == LEFT) ? list->md.moveX - 0.0003 * FPS
	/ list->md.zoom : list->md.moveX;
	list->md.moveX = (keycode == RIGHT) ? list->md.moveX + 0.0003 * FPS
	/ list->md.zoom : list->md.moveX;
	ft_change_fractal(list, keycode);
	printf("iteration max = %f\n", list->md.i_max);
	(keycode == ESC) ? exit(EXIT_SUCCESS) : 0;
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
