/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:20:00 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 18:54:09 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		check_directional_keys(t_env *env, int keycode)
{
	double	tmp;

	if (keycode == 126)
	{
		env->f->strt.y += (env->f->strt.y - env->f->end.y) * env->f->zoom * 10;
		env->f->end.y = env->f->strt.y + (env->f->end.x - env->f->strt.x);
	}
	else if (keycode == 125)
	{
		env->f->strt.y -= (env->f->strt.y - env->f->end.y) * env->f->zoom * 10;
		env->f->end.y = env->f->strt.y + (env->f->end.x - env->f->strt.x);
	}
	else if (keycode == 124)
	{
		tmp = (env->f->end.x - env->f->strt.x) * env->f->zoom * 10;
		env->f->strt.x += tmp;
		env->f->end.x += tmp;
	}
	else if (keycode == 123)
	{
		tmp = (env->f->end.x - env->f->strt.x) * env->f->zoom * 10;
		env->f->strt.x -= tmp;
		env->f->end.x -= tmp;
	}
}

int				close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int				key_pressed_hook(int keycode, void *param)
{
	t_env *env;

	env = param;
	check_directional_keys(env, keycode);
	if (keycode == 116)
		env->f->iter += 1;
	else if (keycode == 121 && env->f->iter > 2)
		env->f->iter -= 1;
	render_fractal(env, env->f);
	return (0);
}
