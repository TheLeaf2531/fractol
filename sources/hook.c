/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:04:15 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/02 22:17:36 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"





int		key_hook(int keycode, void *param)
{
	t_env *env;
	double	tmp;
	
	env = param;
	if (keycode == 65453)
		env->f->zoom *= 1.1;
	else if (keycode == 65451)
		env->f->zoom /= 1.1;
	else if (keycode == 65362)
	{
		env->f->strt.y += (env->f->strt.y - env->f->end.y) * env->f->zoom * 10;
		env->f->end.y = env->f->strt.y + (env->f->end.x - env->f->strt.x);
	}
	else if (keycode == 65364)
	{
		env->f->strt.y -= (env->f->strt.y - env->f->end.y) * env->f->zoom * 10;
		env->f->end.y = env->f->strt.y + (env->f->end.x - env->f->strt.x);
	}
	else if (keycode == 65363)
	{
		tmp = (env->f->end.x - env->f->strt.x) * env->f->zoom * 10;
		env->f->strt.x += tmp;
		env->f->end.x += tmp;
	}
	else if (keycode == 65361)
	{
		tmp = (env->f->end.x - env->f->strt.x) * env->f->zoom * 10;
		env->f->strt.x -= tmp;
		env->f->end.x -= tmp;
	}
	else if (keycode == 65365)
		env->f->iter += 1;
	else if (keycode == 65366 && env->f->iter > 2)
		env->f->iter -= 1;
	else if (keycode == 65307)
		exit(0);
	render_fractal(env, env->f);
	return (0);
}

int		mouse_hook(int button, int x,int y, void *param)
{
	t_complex c;
	t_env *env;

	env = param;
	(void)button;
	/*	
		fractal->c.r = -0.7;
		fractal->c.i = 0.27015;
	*/
	c.r = (x * 100 / WIDTH) - -0.7;
	c.i = (y * 100 / HEIGHT) - 0.27015; 
	env->f->c = c;
	render_fractal(env, env->f);
	return (0);
}
