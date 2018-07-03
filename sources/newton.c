/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:06:11 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 17:28:46 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	*get_newton(void)
{
	t_fractal	*newton;

	if (!(newton = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	newton->x1 = -2;
	newton->x2 = 2;
	newton->y1 = -2;
	newton->y2 = 2;
    newton->c.r = 1.2;
	newton->c.i = 1;
	newton->f = &cp_newton;
	return (newton);
}

int			cp_newton(struct s_fractal *f, int x, int y)
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
		z.r = z_tmp.r * z_tmp.r * z_tmp.r - z_tmp.i * z_tmp.i * z_tmp.i + f->c.r;
		z.i = 2 * z_tmp.r * z_tmp.i + f->c.i;
		if (z.r * z.r + z.i * z.i > 4)
			return (i);
		i++;
	}
    return (i);
}
