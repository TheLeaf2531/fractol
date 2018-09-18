/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 10:32:00 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 15:41:17 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*get_julia_properties(void)
{
	t_fractal *fractal;

	if (!(fractal = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	fractal->strt.x = -2;
	fractal->strt.y = -2;
	fractal->end.x = 2;
	fractal->end.y = fractal->strt.y + (fractal->end.x - fractal->strt.x)
		* HEIGHT / WIDTH;
	fractal->zoom = 1.0 / 256;
	fractal->iter = 10;
	fractal->cp_point = &cp_julia;
	fractal->c.r = -0.7;
	fractal->c.i = 0.27015;
	return (fractal);
}

int			cp_julia(struct s_fractal *f, t_complex c)
{
	t_complex	z;
	t_complex	z_tmp;
	int			i;

	i = 0;
	z.r = c.r;
	z.i = c.i;
	while (z.r * z.r + z.i * z.i < 4 && i < f->iter)
	{
		z_tmp.r = z.r;
		z_tmp.i = z.i;
		z.r = z_tmp.r * z_tmp.r - z_tmp.i * z_tmp.i + f->c.r;
		z.i = 2 * z_tmp.r * z_tmp.i + f->c.i;
		i++;
	}
	return (i);
}
