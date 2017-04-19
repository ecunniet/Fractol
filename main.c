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

void	ft_verif(char *fract, t_env *list)
{
	list->i = (ft_strcmp(fract, "Julia") == 0) ? 1 : 0;
	list->i = (ft_strcmp(fract, "Mandelbrot") == 0
	&& list->i == 0) ? 2 : list->i;
	list->i = (ft_strcmp(fract, "Burning Ship") == 0
	&& list->i == 0) ? 3 : list->i;
	if (list->i == 0)
		ft_error(1, fract);
}

int		main(int argc, char **argv)
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