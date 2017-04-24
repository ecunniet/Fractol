/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:54:53 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/24 15:46:51 by ecunniet         ###   ########.fr       */
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
	if (keycode == MUSIC && list->music.pause_on == 0)
	{
		system("killall -STOP afplay");
		list->music.pause_on = 1;
	}
	else if (keycode == MUSIC && list->music.pause_on == 1)
	{
		system("killall -CONT afplay");
		list->music.pause_on = 0;
	}
	printf("keycode = %d\n", keycode);
	printf("iteration max = %f\n", list->frac.i_max);
	if (keycode == PAUSE)
		list->move.pause = (list->move.pause == 0) ? 1 : 0;
	(keycode == ESC) ? ft_exit_cross(list) : 0;
	return (0);
}

int			ft_mouse_funct(int button, int x, int y, t_env *list)
{
	if (button == 2)
		ft_init(list);
	if (button == 4)
	{
		list->frac.zoom *= pow(1.001, FPS);
		list->frac.moveY -= ((WIDTH / 2) - y) * (0.00005 * FPS / list->frac.zoom) / 9;
		list->frac.moveX -= ((HEIGHT / 2) - x) * (0.00005 * FPS / list->frac.zoom) / 9;
	}
	if (button == 5)
	{
		list->frac.zoom /= pow(1.001, FPS);
		list->frac.moveY += ((WIDTH / 2) - y) * (0.00005 * FPS / list->frac.zoom) / 9;
		list->frac.moveX += ((HEIGHT / 2) - x) * (0.00005 * FPS / list->frac.zoom) / 9;
	}
	return (0);
}

int		ft_loop_ok(t_env *list)
{
	if (list->frac.i_max > 0)
		list->frac.i_max += (list->move.i_more - list->move.i_less);
	if (list->frac.i_max == 0)
		list->frac.i_max += list->move.i_more;
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
	list->move.i_more = 0;
	list->move.i_less = 0;
	list->move.z_more = 0;
	list->move.z_less = 0;
	list->move.up = 0;
	list->move.down = 0;
	list->move.right = 0;
	list->move.left = 0;
	return (0);
}

int		ft_mouse_motion(int x, int y, t_env *list)
{
	if (list->move.on == 1)
	{
		list->frac.moveY += (list->move.y0 - y) * (0.00005 * FPS / list->frac.zoom);
		list->frac.moveX += (list->move.x0 - x) * (0.00005 * FPS / list->frac.zoom);
		list->move.x0 = x;
		list->move.y0 = y;
	}
	else if (list->i == 1 && list->move.pause == 0)
	{
		list->frac.jci = y * (0.00002 * FPS);
		list->frac.jcr = x * (0.00002 * FPS);
	}
	return (0);
}

int		ft_button_press(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	if (button == 1)
	{
		list->move.x0 = x;
		list->move.y0 = y;
		list->move.on = 1;
	}
	ft_mouse_funct(button, x, y, list);
	return (0);
}

int		ft_button_release(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	if (button == 1)
		list->move.on = 0;
	return (0);
}