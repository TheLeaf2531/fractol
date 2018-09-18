/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:59:26 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/02 21:12:05 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*get_burning_properties(void)
{
	t_fractal *fractal;

	if (!(fractal = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	fractal->strt.x = -2;
	fractal->strt.y = -2;
	fractal->end.x = 2;
	fractal->end.y = fractal->strt.y + (fractal->end.x - fractal->strt.x)
		* HEIGHT / WIDTH;
	fractal->zoom = 1./256;
	fractal->iter = 10;
	fractal->cp_point = &cp_burning;
	return (fractal);
}

int			cp_burning(struct s_fractal *f, t_complex c)
{
	t_complex	z;
	long double tmp;
	int			i;

	i = 0;
	z.r = 0;
	z.i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < f->iter)
	{
		tmp = z.r;
		z.r = fabsl(z.r * z.r - z.i * z.i + c.r);
		z.i = fabsl(2 * z.i * tmp + c.i);
        i = i + 1;
	}
	return (i);
}
