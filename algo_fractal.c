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
		*(((int*)list->adi) + tmp) = 0xff23ff + (0x01101100 * list->md.i*255/list->md.i_max);
	else if (true == 0)
		*(((int*)list->adi) + tmp) = 0x000000;

}
void	ft_init(t_env *list)
{
	list->md.zoom = 1;
	list->md.moveX = (list->i == 1) ? 0 : -0.5;
	list->md.moveY = (list->i == 3) ? -0.5 : 0;
	list->md.image_x = WIDTH;
	list->md.image_y = HEIGHT;
	list->md.i_max = 60;
}

int		ft_fractal(t_env *list)
{
	list->md.x = 0;
	while (list->md.x < list->md.image_x)
	{
		list->md.y = 0;
    	while (list->md.y < list->md.image_y)
		{
			list->md.c_r = (list->i == 1) ? -0.7 : 1.5 * (list->md.x - WIDTH / 2) /
			(0.5 * list->md.zoom * WIDTH) + list->md.moveX;
			list->md.c_i = (list->i == 1) ? 0.27015 : (list->md.y - HEIGHT / 2) /
			(0.5 * list->md.zoom * HEIGHT) + list->md.moveY;
			list->md.z_r = (list->i == 1) ? 1.5 * (list->md.x - WIDTH / 2) /
			(0.5 * list->md.zoom * WIDTH) + list->md.moveX : 0;
			list->md.z_i = (list->i == 1) ? (list->md.y - HEIGHT / 2) /
			(0.5 * list->md.zoom * HEIGHT) + list->md.moveY : 0;
			list->md.i = 0;
        	while (list->md.z_r * list->md.z_r + list->md.z_i * list->md.z_i < 4 && list->md.i < list->md.i_max)
			{
				list->md.tmp = list->md.z_r;
 	        	list->md.z_r = list->md.z_r * list->md.z_r
 	        	- list->md.z_i * list->md.z_i + list->md.c_r;
        	    list->md.z_i = (list->i == 3) ? 2 * fabs(list->md.z_i * list->md.tmp)
        	    + list->md.c_i : 2 * list->md.z_i * list->md.tmp + list->md.c_i;
           	 	list->md.i++;
			}
            if (list->md.i != list->md.i_max)
				ft_pixel_put_image(list, list->md.x, list->md.y, 1);
			else
				ft_pixel_put_image(list, list->md.x, list->md.y, 0);
			list->md.y++;
    	}
		list->md.x++;
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
	mlx_key_hook(list->win, ft_key_funct, list);
	mlx_mouse_hook(list->win, ft_mouse_funct, list);
	mlx_loop_hook(list->mlx, &ft_fractal, list);
	mlx_loop(list->mlx);
	return (0);
}
