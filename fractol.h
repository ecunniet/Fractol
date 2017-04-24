/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:55:12 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/24 14:26:47 by ecunniet         ###   ########.fr       */
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
#define PAUSE 36
#define MUSIC 46
// mlx defines
#define KEYPRESSEVENT 2
#define KEYPRESSMASK (1L << 0)
#define KEYRELEASEEVENT 3
#define KEYRELEASEMASK (1L << 1)
#define BUTTONPRESS 4
#define BUTTONPRESSMASK (1L << 2)
#define BUTTONRELEASE 5
#define BUTTONRELEASEMASK (1L << 3)
#define MOTIONNOTIFY 6
#define POINTERMOTIONMASK (1L << 6)
#define DESTROYNOTIFY 17
#define STRUCTURENOTIFYMASK (1L << 17)

typedef struct 		s_music
{
	int				music_on;
	int				pause_on;
}					t_music;

typedef struct		s_cmd
{
	int				pause;
	int				x0;
	int				y0;
	int				on;
	int				up;
	int				down;
	int				right;
	int				left;
	int				z_more;
	int				z_less;
	int				i_more;
	int				i_less;
}					t_cmd;

typedef	struct		s_frac
{
	double			image_x;
	double			image_y;
	double			moveX;
	double			moveY;
	double			i_max;
	double			zoom;
	double			x;
	double			jcr;
	double			jci;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
	double			tmp;
	double			y;
}					t_frac;

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
	int				i;
	t_music			music;
	t_frac			frac;
	t_cmd			move;
}					t_env;

void			ft_init(t_env *list);
int				ft_fractal(t_env *list);
int				ft_loop_ok(t_env *list);
int				ft_key_release(int keycode, t_env *list);
int				ft_key_press(int keycode, t_env *list);
void			ft_music(t_env *list);
int				ft_button_release(int button, int x, int y, t_env *list);
int				ft_button_press(int button, int x, int y, t_env *list);
int				ft_mouse_motion(int x, int y, t_env *list);
int				ft_exit(t_env *list);
void			ft_error(int i, char *str);

#endif
