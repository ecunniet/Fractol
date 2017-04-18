/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:20:31 by ecunniet          #+#    #+#             */
/*   Updated: 2017/01/25 15:51:01 by ecunniet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_error(int i, char *str)
{
	if (i == 1)
	{
		ft_putstr("Error: Parameter ");
		ft_putstr(str);
		ft_putstr(" doesn't exist.\n");
	}
	ft_putstr("Usage: ./fractol fractal_name:\n-Julia\n-Mandelbrot\n-Cesaro\n");
	exit(EXIT_FAILURE);
}
