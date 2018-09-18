/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 22:02:51 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 15:43:34 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*get_mandel_properties(void)
{
	t_fractal *fractal;

	if (!(fractal = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	fractal->strt.x = -0.3;
	fractal->strt.y = 0.6;
	fractal->end.x = 2;
	fractal->end.y = fractal->strt.y + (fractal->end.x - fractal->strt.x)
		* HEIGHT / WIDTH;
	fractal->zoom = 1.0 / 256;
	fractal->cp_point = &cp_mandelbrot;
	fractal->iter = 10;
	return (fractal);
}

int			cp_mandelbrot(struct s_fractal *f, t_complex c)
{
	t_complex	z;
	t_complex	z_2;
	int			i;

	i = 0;
	z.r = 0;
	z.i = 0;
	z_2.r = 0;
	z_2.i = 0;
	while (z_2.r + z_2.i < 4 && i < f->iter)
	{
		z.i = 2 * z.r * z.i + c.i;
		z.r = z_2.r - z_2.i + c.r;
		z_2.r = z.r * z.r;
		z_2.i = z.i * z.i;
		i += 1;
	}
	return (i);
}
