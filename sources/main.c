/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:54:31 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 18:51:26 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env			*init_mlx(void)
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

void			error_msg(void)
{
	ft_putstr("usage: fractol [<arg>]\n");
	ft_putstr("   mandelbrot\n");
	ft_putstr("   julia\n");
	ft_putstr("   burning_ship\n");
	exit(0);
}

int				main(int argc, char **argv)
{
	t_env		*env;
	t_fractal	*f;

	f = NULL;
	if (argc != 2)
		error_msg();
	if (ft_strcmp(argv[1], "julia") == 0)
		f = get_julia_properties();
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		f = get_mandel_properties();
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		f = get_burning_properties();
	else
		error_msg();
	env = init_mlx();
	env->f = f;
	env->f->col = 196;
	render_fractal(env, env->f);
	mlx_key_hook(env->win_ptr, &key_hook, env);
	mlx_mouse_hook(env->win_ptr, &mouse_hook, env);
	mlx_hook(env->win_ptr, 6, (1L << 6), &house_move_hook, env);
	mlx_hook(env->win_ptr, 17, (1L << 17), &close_hook, env);
	mlx_hook(env->win_ptr, 2, (1L << 2), &key_pressed_hook, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
