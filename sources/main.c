/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:54:31 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/02 22:12:08 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env		*init_mlx()
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "Fractol")))
		return (NULL);
	return (e);
}

int		main(int argc, char **argv)
{
	pthread_t	thread;
	t_sqrdt		test;
	t_env		*env;
	t_fractal	*fractal;
	t_square	**sqrs;

	env = init_mlx();
	env->f = get_julia_properties();
	render_fractal(env, env->f);
	mlx_key_hook(env->win_ptr, &key_hook, env);
	mlx_mouse_hook(env->win_ptr, &mouse_hook, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}