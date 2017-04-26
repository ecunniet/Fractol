/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:01:12 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/25 13:54:15 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_pixel_put_image(t_env *list, int x, int y, int true)
{
	int tmp;

	tmp = (x + (y * WIDTH));
	if (y >= 0 && x >= 0 && true == 1)
		*(((int*)list->adi) + tmp) = 0xff23ff +
	(0x01101100 * (list->frac.i * 255 / list->frac.i_max));
	else if (true == 0)
		*(((int*)list->adi) + tmp) = 0x000000;
}

static void		ft_string_fracal(t_env *list)
{
	char	*str;

	if (list->i == 1)
		mlx_string_put(list->mlx, list->win, 15, 15, 0xffffff, "JULIA");
	else if (list->i == 2)
		mlx_string_put(list->mlx, list->win, 15, 15, 0xffffff, "MENDELBROT");
	else
		mlx_string_put(list->mlx, list->win, 15, 15, 0xffffff, "BURNING SHIP");
	mlx_string_put(list->mlx, list->win, 15, 35, 0xffffff, "Iteration max = ");
	str = ft_itoa(list->frac.i_max);
	mlx_string_put(list->mlx, list->win, 175,
	35, 0xffffff, str);
	free(str);
}

void			ft_init(t_env *list)
{
	list->frac.zoom = 1;
	list->frac.movex = (list->i == 1) ? 0 : -0.5;
	list->frac.movey = (list->i == 3) ? -0.5 : 0;
	list->frac.image_x = WIDTH;
	list->frac.image_y = HEIGHT;
	list->frac.jcr = -0.7;
	list->frac.jci = 0.27015;
	list->frac.i_max = 60;
	list->move.pause = 0;
	list->move.x0 = 0;
	list->move.y0 = 0;
	list->move.on = 0;
	list->move.up = 0;
	list->move.down = 0;
	list->move.right = 0;
	list->move.left = 0;
	list->move.z_more = 0;
	list->move.z_less = 0;
	list->move.i_more = 0;
	list->move.i_less = 0;
	list->music.pause_on = 0;
	ft_music(list);
}

static void		ft_in_fractal(t_env *list, int i)
{
	if (i == 1)
	{
		list->frac.c_r = (list->i == 1) ? list->frac.jcr : 1.5 *
		(list->frac.x - WIDTH / 2) / (0.5 *
		list->frac.zoom * WIDTH) + list->frac.movex;
		list->frac.c_i = (list->i == 1) ? list->frac.jci :
		(list->frac.y - HEIGHT / 2) / (0.5 *
		list->frac.zoom * HEIGHT) + list->frac.movey;
		list->frac.z_r = (list->i == 1) ? 1.5 * (list->frac.x - WIDTH / 2) /
		(0.5 * list->frac.zoom * WIDTH) + list->frac.movex : 0;
		list->frac.z_i = (list->i == 1) ? (list->frac.y - HEIGHT / 2) /
		(0.5 * list->frac.zoom * HEIGHT) + list->frac.movey : 0;
		list->frac.i = 0;
	}
	else
	{
		list->frac.tmp = list->frac.z_r;
		list->frac.z_r = list->frac.z_r * list->frac.z_r
		- list->frac.z_i * list->frac.z_i + list->frac.c_r;
		list->frac.z_i = (list->i == 3) ? 2 *
		fabs(list->frac.z_i * list->frac.tmp) + list->frac.c_i : 2
		* list->frac.z_i * list->frac.tmp + list->frac.c_i;
		list->frac.i++;
	}
}

int				ft_fractal(t_env *list)
{
	list->frac.x = 0;
	while (list->frac.x < list->frac.image_x)
	{
		list->frac.y = 0;
		while (list->frac.y < list->frac.image_y)
		{
			ft_in_fractal(list, 1);
			while (list->frac.z_r * list->frac.z_r + list->frac.z_i *
			list->frac.z_i < 4 && list->frac.i < list->frac.i_max)
				ft_in_fractal(list, 2);
			if (list->frac.i != list->frac.i_max)
				ft_pixel_put_image(list, list->frac.x, list->frac.y, 1);
			else
				ft_pixel_put_image(list, list->frac.x, list->frac.y, 0);
			list->frac.y++;
		}
		list->frac.x++;
	}
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	ft_string_fracal(list);
	return (0);
}
