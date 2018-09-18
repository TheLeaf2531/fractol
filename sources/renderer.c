/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 22:26:05 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 17:33:26 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(t_mlx_img *image, unsigned int color,
				t_coordi p, t_coordi res)
{
	image->img[p.y * res.x + p.x] = color;
}

void			fill_image(t_mlx_img *image, unsigned int color, t_coordi res)
{
	size_t	img_size;
	size_t	i;

	img_size = (res.x - 1) * (res.y - 1);
	i = 0;
	while (i < img_size)
	{
		image->img[i] = color;
		i++;
	}
}

unsigned int	col_point(int i, int max_i, float h)
{
	t_hsvcolor col;

	col.h = h;
	col.s = 1.0;
	col.v = 1.0;
	if (i == max_i)
		return (0);
	return (hsv_to_color(col.h, col.s, fmod((i % max_i * 0.1), 1.0)));
}

void			*sqr_renderer(void *arg)
{
	t_sqrdt		*t;
	t_coordi	p;
	t_complex	c;
	t_coordi	res;
	t_coordi	wp;

	t = arg;
	res.x = t->sqr->end.x - t->sqr->strt.x;
	res.y = t->sqr->end.y - t->sqr->strt.y;
	p = set_coordi(t->sqr->strt.x, t->sqr->strt.y);
	while (p.y < t->sqr->end.y)
	{
		c.i = (p.y - (HEIGHT) / 2) * t->f->zoom + t->f->strt.y;
		while (p.x < t->sqr->end.x)
		{
			wp.x = t->sqr->strt.x != 0 ? p.x % t->sqr->strt.x : p.x;
			wp.y = t->sqr->strt.y != 0 ? p.y % t->sqr->strt.y : p.y;
			c.r = (p.x - (WIDTH) / 2) * t->f->zoom + t->f->strt.x;
			put_pixel(t->sqr->img, col_point(t->f->cp_point(t->f, c),
				t->f->iter, t->f->col), wp, res);
			p.x += 1;
		}
		p = set_coordi(0, p.y + 1);
	}
	pthread_exit(NULL);
}

int				render_fractal(t_env *env, t_fractal *f)
{
	pthread_t	thread[8];
	t_square	**sqrs;
	t_sqrdt		dt[8];
	int			i;

	if (!(sqrs = cr_squares(env->mlx_ptr)))
		return (0);
	i = 0;
	while (i < 8)
	{
		dt[i].f = f;
		dt[i].sqr = sqrs[i];
		pthread_create(&thread[i], NULL, sqr_renderer, &dt[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(thread[i], NULL);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
			dt[i].sqr->img->img_ptr, dt[i].sqr->strt.x, dt[i].sqr->strt.y);
		i++;
	}
	sqrdel(env, dt, sqrs);
	return (1);
}
