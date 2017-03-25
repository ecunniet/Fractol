/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:16:57 by ecunniet          #+#    #+#             */
/*   Updated: 2017/02/02 21:56:07 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

void			ft_error(int i, char *str);

typedef	struct		s_frac
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	image_x;
	double	image_y;
	double	iteration_max;
	double	zoom_x;
	double	zoom_y;
	double	x;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	i;
	double tmp;
	double	y;
}			t_frac;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char			*adi;
	double			zoom;
	int			i;
	t_frac			md;
}			t_env;

#endif
