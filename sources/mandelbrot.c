/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:01:13 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 16:01:58 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			cp_mandelbrot(struct s_fractal *f, int x, int y)
{
	long double c_r;
	long double c_i;
	long double z_r;
	long double z_i;
	long double tmp;
	int			i;

	i = 0;
	c_r = x / f->zoom_x + f->x1;
	c_i = y / f->zoom_y + f->y1;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < ITER)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
        i = i + 1;
	}
	return (i);
}

t_fractal	*get_mandel(void)
{
	t_fractal *mandel;

	if (!(mandel = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	mandel->x1 = -2;
	mandel->x2 = 2;
	mandel->y1 = -2;
	mandel->y2 = 2;
	mandel->f = &cp_mandelbrot;
	return (mandel);
}
