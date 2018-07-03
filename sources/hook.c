/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:05:09 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 17:19:20 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_hook(int keycode, void *param)
{
	t_env				*e;
	long double			diff_x;
	long double			diff_y;

	e = param;
	diff_x = sqrtl(powl(e->f->x2 - e->f->x1, 2.0)) * 0.1;
	diff_y = sqrtl(powl(e->f->y2 - e->f->y1, 2.0)) * 0.1;
	if (keycode == 53)
	{
		exit(0);
	}
	if (keycode == 124)
	{
		e->f->x1 += diff_x;
		e->f->x2 += diff_x;
	}
	if (keycode == 123)
	{
		e->f->x1 -= diff_x;
		e->f->x2 -= diff_x;
	}
	if (keycode == 126)
	{
		e->f->y1 -= diff_y;
		e->f->y2 -= diff_y;
	}
	if (keycode == 125)
	{
		e->f->y1 += diff_y;
		e->f->y2 += diff_y;
	}
	draw_fractal(e, e->f);
	display_pos(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, void *param)
{
	t_env				*e;
	long double			diff_x;
	long double			diff_y;

	e = param;
	(void)x;
	(void)y;
	diff_x = sqrtl(powl(e->f->x2 - e->f->x1, 2.0));
	diff_y = sqrtl(powl(e->f->y2 - e->f->y1, 2.0));
	if (button == 4)
	{
		e->f->x1 += diff_x * (long double)0.25;
		e->f->x2 -= diff_x * (long double)0.25;
		e->f->y1 += diff_y * (long double)0.25;
		e->f->y2 -= diff_y * (long double)0.25;
		draw_fractal(e, e->f);
	}
	if (button == 5)
	{
		e->f->x1 -= diff_x * (long double)0.25;
		e->f->x2 += diff_x * (long double)0.25;
		e->f->y1 -= diff_y * (long double)0.25;
		e->f->y2 += diff_y * (long double)0.25;
		draw_fractal(e, e->f);
	}
	display_pos(e);
	return (0);
}

int		expose_hook(void *param)
{
	t_env *e;

	e = param;
	draw_fractal(e, e->f);
	display_pos(e);
	return (0);
}
