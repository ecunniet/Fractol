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

int			ft_key_funct(int keycode, t_env *list)
{
	int		tmp;

	tmp = list->i;
	list->i = (keycode == ONE) ? 1 : list->i;
	list->i = (keycode == TWO) ? 2 : list->i;
	list->i = (keycode == THREE) ? 3 : list->i;
	if (list->i != tmp)
		ft_init(list);
	printf("keycode = %d\n", keycode);
	printf("iteration max = %f\n", list->frac.i_max);
	if (keycode == PAUSE)
		list->move.pause = (list->move.pause == 0) ? 1 : 0;
	(keycode == ESC) ? exit(EXIT_SUCCESS) : 0;
	return (0);
}

int			ft_mouse_funct(int button, int x, int y, t_env *list)
{
	if (button == 2)
		ft_init(list);
/*	if (button == 4)
	{
		//zoom sur le curseur de la sourie
		
		list->frac.x1 = (x > 500) ? list->frac.x1 * 0.5: list->frac.x1;
		list->frac.x2 = (x < 500) ? list->frac.x2 * 0.5: list->frac.x2;
		list->frac.y1 = (y > 375) ? list->frac.y1 * 0.5: list->frac.y1;
		list->frac.y2 = (y < 375) ? list->frac.y2 * 0.5: list->frac.y2;
		// printf("x1 = %f, x2 = %f, y1 = %f, y2 = %f\n", list->frac.x1, list->frac.x2, list->frac.y1, list->frac.y2);
	
	}
	if (button == 5)
	{
	// dsezoom sur curseur
	
		list->frac.x1 = (x > 500) ? list->frac.x1 * 2: list->frac.x1;
		list->frac.x2 = (x < 500) ? list->frac.x2 * 2: list->frac.x2;
		list->frac.y1 = (y > 375) ? list->frac.y1 * 2: list->frac.y1;
		list->frac.y2 = (y < 375) ? list->frac.y2 * 2: list->frac.y2;
		// printf("x1 = %f, x2 = %f, y1 = %f, y2 = %f\n", list->frac.x1, list->frac.x2, list->frac.y1, list->frac.y2);
	/	
	}*/
	return (0);
}

int		ft_loop_ok(t_env *list)
{
	list->frac.i_max += (list->move.i_more - list->move.i_less);
	if(list->move.z_more != 0 || list->move.z_less != 0)
		list->frac.zoom *= ((list->move.z_more * pow(1.001, FPS)) + (list->move.z_less / pow(1.001, FPS)));
	list->frac.moveY += (list->move.down - list->move.up) * (0.0013 * FPS / list->frac.zoom);
	list->frac.moveX += (list->move.right - list->move.left) * (0.0013 * FPS / list->frac.zoom);
	ft_fractal(list);
	return (0);
}

int		ft_key_press(int keycode, t_env *list)
{
	list->move.i_more = (keycode == I) ? 1 : 0;
	list->move.i_less = (keycode == O) ? 1 : 0;
	list->move.z_more = (keycode == MORE) ? 1 : 0;
	list->move.z_less = (keycode == LESS) ? 1 : 0;
	list->move.up = (keycode == UP) ? 1 : 0;
	list->move.down = (keycode == DOWN) ? 1 : 0;
	list->move.right = (keycode == RIGHT) ? 1 : 0;
	list->move.left = (keycode == LEFT) ? 1 : 0;
	ft_key_funct(keycode, list);
	return (0);
}

int		ft_key_release(int keycode, t_env *list)
{
	list->move.i_more = (keycode == I) ? 0 : 0;
	list->move.i_less = (keycode == O) ? 0 : 0;
	list->move.z_more = (keycode == MORE) ? 0 : 0;
	list->move.z_less = (keycode == LESS) ? 0 : 0;
	list->move.up = (keycode == UP) ? 0 : 0;
	list->move.down = (keycode == DOWN) ? 0 : 0;
	list->move.right = (keycode == RIGHT) ? 0 : 0;
	list->move.left = (keycode == LEFT) ? 0 : 0;
	return (0);
}

int		ft_mouse_motion(int x, int y, t_env *list)
{
	if (list->move.on == 0 && list->i == 1 && list->move.pause == 0)
	{
		list->frac.c_i = y;
		list->frac.c_r = x;
	}
	else if (list->move.on == 1)
	{
		list->frac.moveY += (list->move.y0 - y) * (0.00003 * FPS / list->frac.zoom) / 6;
		list->frac.moveX += (list->move.x0 - x) * (0.00003 * FPS / list->frac.zoom) / 6;
	}
	return (0);
}

int		ft_button_press(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	if (button == 1)
	{
	// pour recentrer faire une difference avec x et y vis a vis du centre comme ca toute la fractal est decaller
		list->move.x0 = x;
		list->move.y0 = y;
		list->move.on = 1;
		list->move.pause = 1;
	}
	ft_mouse_funct(button, x, y, list);
	return (0);
}

int		ft_button_release(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	list->move.pause = 0;
	if (button == 1)
		list->move.on = 0;
		list->move.pause = 0;
	return (0);
}

/*list->frac.i_max = (keycode == O && list->frac.i_max >= 10) ?
	list->frac.i_max - 10 : list->frac.i_max;
	list->frac.zoom = (keycode == MORE) ? list->frac.zoom *
	pow(1.001, FPS) : list->frac.zoom;
	list->frac.zoom = (keycode == LESS) ? list->frac.zoom /
	pow(1.001, FPS) : list->frac.zoom;
	list->frac.moveY = (keycode == UP) ? list->frac.moveY - 0.0003 * FPS
	/ list->frac.zoom : list->frac.moveY;
	list->frac.moveY = (keycode == DOWN) ? list->frac.moveY + 0.0003 * FPS
	/ list->frac.zoom : list->frac.moveY;
	list->frac.moveX = (keycode == LEFT) ? list->frac.moveX - 0.0003 * FPS
	/ list->frac.zoom : list->frac.moveX;
	list->frac.moveX = (keycode == RIGHT) ? list->frac.moveX + 0.0003 * FPS
	/ list->frac.zoom : list->frac.moveX;
*/