/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:02:18 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 16:02:52 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			cp_julia(struct s_fractal *f, int x, int y)
{
	t_complex	z;
	t_complex	z_tmp;
	int			i;

	i = 0;
	z.r = x / f->zoom_x + f->x1;
	z.i = y / f->zoom_y + f->y1;
	while (i < ITER)
	{
		z_tmp.r = z.r;
		z_tmp.i = z.i;
		z.r = z_tmp.r * z_tmp.r - z_tmp.i * z_tmp.i + f->c.r;
		z.i = 2 * z_tmp.r * z_tmp.i + f->c.i;
		if (z.r * z.r + z.i * z.i > 4)
			return (i);
		i++;
	}
	return (i);
}

t_fractal	*get_julia(void)
{
	t_fractal *f;

	if (!(f = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	f->x1 = -2;
	f->x2 = 2;
	f->y1 = -2;
	f->y2 = 2;
	f->f = &cp_julia;
	f->zoom = 0.8;
	f->c.r = -0.7;
	f->c.i = 0.27015;
	return (f);
}