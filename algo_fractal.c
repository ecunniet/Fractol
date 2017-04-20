/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:41:09 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/19 16:47:34 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put_image(t_env *list, int x, int y, int true)
{
	int tmp;

	tmp = (x + (y * WIDTH));
	if (y >= 0 && x >= 0 && true == 1)
		*(((int*)list->adi) + tmp) = 0xff23ff + (0x01101100 * list->frac.i*255/list->frac.i_max);
	else if (true == 0)
		*(((int*)list->adi) + tmp) = 0x000000;

}

void	ft_init(t_env *list)
{
	list->frac.zoom = 1;
	list->frac.moveX = (list->i == 1) ? 0 : -0.5;
	list->frac.moveY = (list->i == 3) ? -0.5 : 0;
	list->frac.image_x = WIDTH;
	list->frac.image_y = HEIGHT;
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
}

int		ft_fractal(t_env *list)
{
	list->frac.x = 0;
	while (list->frac.x < list->frac.image_x)
	{
		list->frac.y = 0;
    	while (list->frac.y < list->frac.image_y)
		{
			list->frac.c_r = (list->i == 1) ? -0.7 : 1.5 * (list->frac.x - WIDTH / 2) /
			(0.5 * list->frac.zoom * WIDTH) + list->frac.moveX;
			list->frac.c_i = (list->i == 1) ? 0.27015 : (list->frac.y - HEIGHT / 2) /
			(0.5 * list->frac.zoom * HEIGHT) + list->frac.moveY;
			list->frac.z_r = (list->i == 1) ? 1.5 * (list->frac.x - WIDTH / 2) /
			(0.5 * list->frac.zoom * WIDTH) + list->frac.moveX : 0;
			list->frac.z_i = (list->i == 1) ? (list->frac.y - HEIGHT / 2) /
			(0.5 * list->frac.zoom * HEIGHT) + list->frac.moveY : 0;
			list->frac.i = 0;
        	while (list->frac.z_r * list->frac.z_r + list->frac.z_i * list->frac.z_i < 4 && list->frac.i < list->frac.i_max)
			{
				list->frac.tmp = list->frac.z_r;
 	        	list->frac.z_r = list->frac.z_r * list->frac.z_r
 	        	- list->frac.z_i * list->frac.z_i + list->frac.c_r;
        	    list->frac.z_i = (list->i == 3) ? 2 * fabs(list->frac.z_i * list->frac.tmp)
        	    + list->frac.c_i : 2 * list->frac.z_i * list->frac.tmp + list->frac.c_i;
           	 	list->frac.i++;
			}
            if (list->frac.i != list->frac.i_max)
				ft_pixel_put_image(list, list->frac.x, list->frac.y, 1);
			else
				ft_pixel_put_image(list, list->frac.x, list->frac.y, 0);
			list->frac.y++;
    	}
		list->frac.x++;
	}
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	return (0);
}

int		ft_draw_pix(t_env *list)
{
	list->mlx = mlx_init();
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "mlx_42");
	list->img_ptr = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	list->adi = mlx_get_data_addr(list->img_ptr, &list->bpp,
	&list->size_line, &list->endian);
	ft_init(list);
	ft_fractal(list);
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	mlx_hook(list->win, KEYPRESSEVENT, KEYPRESSMASK, &ft_key_press, list);
	mlx_hook(list->win, KEYRELEASEEVENT, KEYRELEASEMASK, &ft_key_release, list);
	mlx_hook(list->win, MOTIONNOTIFY, POINTERMOTIONMASK, &ft_mouse_motion, list);
	mlx_hook(list->win, BUTTONPRESS, BUTTONPRESSMASK, &ft_button_press, list);
	mlx_hook(list->win, BUTTONRELEASE, BUTTONRELEASEMASK, &ft_button_release, list);
	mlx_hook(list->win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &ft_exit_cross, list);
	mlx_loop_hook(list->mlx, &ft_loop_ok, list);
	mlx_loop(list->mlx);
	return (0);
}