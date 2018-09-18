/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:04:15 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 18:55:03 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		check_color_keys(t_env *env, int keycode)
{
	if (keycode == 18)
		env->f->col = 90;
	if (keycode == 19)
		env->f->col = 196;
	if (keycode == 20)
		env->f->col = 270;
	if (keycode == 21)
		env->f->col = 360;
}

int				key_hook(int keycode, void *param)
{
	t_env *env;

	env = param;
	check_color_keys(env, keycode);
	if (keycode == 53)
		exit(0);
	render_fractal(env, env->f);
	return (0);
}

int				house_move_hook(int x, int y, void *param)
{
	t_complex	c;
	t_env		*env;

	env = param;
	c.r = (x * 100 / WIDTH) * -0.01;
	c.i = (y * 100 / HEIGHT) * 0.01;
	env->f->c = c;
	render_fractal(env, env->f);
	return (0);
}

int				mouse_hook(int button, int x, int y, void *param)
{
	t_env		*env;

	(void)x;
	(void)y;
	env = param;
	if (button == 5)
		env->f->zoom *= 1.1;
	else if (button == 4)
		env->f->zoom /= 1.1;
	render_fractal(env, env->f);
	return (0);
}
