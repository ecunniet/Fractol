/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:22:35 by ecunniet          #+#    #+#             */
/*   Updated: 2017/04/19 16:29:32 by ecunniet         ###   ########.fr       */
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
	ft_putstr("Usage: ./fractol fractal_name:\n-Julia\n-Mandelbrot\n-Burning Ship\n");
	exit(EXIT_FAILURE);
}
