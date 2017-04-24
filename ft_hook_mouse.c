#include "fractol.h"

static int	ft_mouse_funct(int button, int x, int y, t_env *list)
{
	if (button == 2)
		ft_init(list);
	if (button == 4)
	{
		list->frac.zoom *= pow(1.001, FPS);
		list->frac.moveY -= ((WIDTH / 2) - y) *
		(0.00005 * FPS / list->frac.zoom) / 9;
		list->frac.moveX -= ((HEIGHT / 2) - x) *
		(0.00005 * FPS / list->frac.zoom) / 9;
	}
	if (button == 5)
	{
		list->frac.zoom /= pow(1.001, FPS);
		list->frac.moveY += ((WIDTH / 2) - y) *
		(0.00005 * FPS / list->frac.zoom) / 9;
		list->frac.moveX += ((HEIGHT / 2) - x) *
		(0.00005 * FPS / list->frac.zoom) / 9;
	}
	return (0);
}

int			ft_mouse_motion(int x, int y, t_env *list)
{
	if (list->move.on == 1)
	{
		list->frac.moveY += (list->move.y0 - y) *
		(0.00005 * FPS / list->frac.zoom);
		list->frac.moveX += (list->move.x0 - x) *
		(0.00005 * FPS / list->frac.zoom);
		list->move.x0 = x;
		list->move.y0 = y;
	}
	else if (list->i == 1 && list->move.pause == 0)
	{
		list->frac.jci = y * (0.00002 * FPS);
		list->frac.jcr = x * (0.00002 * FPS);
	}
	return (0);
}

int			ft_button_press(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	if (button == 1)
	{
		list->move.x0 = x;
		list->move.y0 = y;
		list->move.on = 1;
	}
	ft_mouse_funct(button, x, y, list);
	return (0);
}

int			ft_button_release(int button, int x, int y, t_env *list)
{
	printf("button = %d et x = %d et y = %d\n", button, x, y);
	if (button == 1)
		list->move.on = 0;
	return (0);
}
