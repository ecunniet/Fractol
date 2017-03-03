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

void				ft_error(int i, char *str);


typedef struct		s_env
{
	int				fd;
	void			*mlx;
	void			*win;
	char			*line;
	void			*img_ptr;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
	char			*adi;
	int				color;
	double			zoom;
	int				center_x;
	int				center_y;
	double			angle_y;
	double			angle_x;
	double			angle_z;
	int				b_x;
	int				b_y;
	int				b_z;
	char			*str;
	int				rainbow;
	int				nblR;
	int				modR;
	int				*R;
	int				i;
}					t_env;

typedef	struct		s_line
{
	int				dx;
	int				dy;
	int				err;
	int				xi;
	int				yi;
	int				xf;
	int				yf;
	int				xinc;
	int				yinc;
	int				i;
}					t_line;

#endif
