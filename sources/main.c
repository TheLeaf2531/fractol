/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:24:50 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 17:19:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		display_pos(t_env *e)
{
	char output[50];

	snprintf(output, 50, "%Lf", e->f->x1);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 0, to_color(255, 255, 255, 0), output);
	snprintf(output, 50, "%Lf", e->f->x2);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 20, to_color(255, 255, 255, 0), output);
	snprintf(output, 50, "%Lf", e->f->y1);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 40, to_color(255, 255, 255, 0), output);
	snprintf(output, 50, "%Lf", e->f->y2);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 60, to_color(255, 255, 255, 0), output);
}

t_env		*start_mlx()
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

int			main(int argc, char **argv)
{
	t_env	*e;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr("TODO: Message d'erreur\n");
		return (0);
	}
	if (!(e = start_mlx()))
		return (0);
	if (!(e->f = get_newton()))
		return (0);
	mlx_key_hook(e->win_ptr, &key_hook, e);
	mlx_mouse_hook(e->win_ptr, &mouse_hook, e);
	mlx_expose_hook(e->win_ptr, &expose_hook, e);
	draw_fractal(e, e->f);
	mlx_loop(e->mlx_ptr);
	return (0);
}
