/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:27:38 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/19 16:30:47 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_draw_pix(t_env *list)
{
	list->mlx = mlx_init();
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "mlx_42");
	list->img_ptr = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	list->adi = mlx_get_data_addr(list->img_ptr, &list->bpp,
	&list->size_line, &list->endian);
	list->music.music_on = 0;
	ft_init(list);
	ft_fractal(list);
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	mlx_hook(list->win, KEYPRESSEVENT, KEYPRESSMASK, &ft_key_press, list);
	mlx_hook(list->win, KEYRELEASEEVENT, KEYRELEASEMASK,
	&ft_key_release, list);
	mlx_hook(list->win, MOTIONNOTIFY, POINTERMOTIONMASK,
	&ft_mouse_motion, list);
	mlx_hook(list->win, BUTTONPRESS, BUTTONPRESSMASK, &ft_button_press, list);
	mlx_hook(list->win, BUTTONRELEASE, BUTTONRELEASEMASK,
	&ft_button_release, list);
	mlx_hook(list->win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &ft_exit, list);
	mlx_loop_hook(list->mlx, &ft_loop_ok, list);
	mlx_loop(list->mlx);
	return (0);
}

static void		ft_verif(char *fract, t_env *list)
{
	list->i = (ft_strcmp(fract, "Julia") == 0) ? 1 : 0;
	list->i = (ft_strcmp(fract, "Mandelbrot") == 0
	&& list->i == 0) ? 2 : list->i;
	list->i = (ft_strcmp(fract, "Burning Ship") == 0
	&& list->i == 0) ? 3 : list->i;
	if (list->i == 0)
		ft_error(1, fract);
}

int				main(int argc, char **argv)
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
