/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:55:12 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/19 16:30:44 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 1000
#define HEIGHT 750
#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
#define MORE 24
#define LESS 27
#define I 34
#define O 31
#define ESC 53
#define FPS 60
#define ONE 18
#define TWO 19
#define THREE 20

typedef	struct		s_frac
{
	double			image_x;
	double			image_y;
	double			moveX;
	double			moveY;
	double			i_max;
	double			zoom;
	double			x;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	double			y;
}				t_frac;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	char			*adi;
	double			zoom;
	char			r_gb;
	char			r_g_b;
	char			rg_b;
	int				i;
	t_frac			md;
}					t_env;


void			ft_change_fractal(t_env *list, int keycode);
void			ft_pixel_put_image(t_env *list, int x, int y, int true);
void			ft_init(t_env *list);
int				ft_fractal(t_env *list);
int				ft_draw_pix(t_env *list);
int				ft_key_funct(int keycode, t_env *list);
int				ft_mouse_funct(int button, int x, int y, t_env *list);
void			ft_error(int i, char *str);

#endif
