/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:02:20 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/25 12:02:23 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mouse_funct(int button, int x, int y, t_env *list)
{
	if (button == 2)
		ft_init(list);
	if (button == 4)
	{
		list->frac.zoom *= pow(1.001, FPS);
		list->frac.movey -= ((WIDTH / 2) - y) *
		(0.00005 * FPS / list->frac.zoom) / 9;
		list->frac.movex -= ((HEIGHT / 2) - x) *
		(0.00005 * FPS / list->frac.zoom) / 9;
	}
	if (button == 5)
	{
		list->frac.zoom /= pow(1.001, FPS);
		list->frac.movey += ((WIDTH / 2) - y) *
		(0.00005 * FPS / list->frac.zoom) / 9;
		list->frac.movex += ((HEIGHT / 2) - x) *
		(0.00005 * FPS / list->frac.zoom) / 9;
	}
	return (0);
}

int			ft_mouse_motion(int x, int y, t_env *list)
{
	if (list->move.on == 1)
	{
		list->frac.movey += (list->move.y0 - y) *
		(0.00005 * FPS / list->frac.zoom);
		list->frac.movex += (list->move.x0 - x) *
		(0.00005 * FPS / list->frac.zoom);
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

int			ft_button_press(int button, int x, int y, t_env *list)
{
	if (button == 1)
	{
		list->move.x0 = x;
		list->move.y0 = y;
		list->move.on = 1;
	}
	ft_mouse_funct(button, x, y, list);
	return (0);
}

int			ft_button_release(int button, int x, int y, t_env *list)
{
	if (button == 1)
		list->move.on = 0;
	return (0);
}
