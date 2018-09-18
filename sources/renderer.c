/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 22:26:05 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/02 21:47:58 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_mlx_img *image, unsigned int color, t_coordi p, t_coordi res)
{
	image->img[p.y * res.x + p.x] = color;
}

void		fill_image(t_mlx_img *image, unsigned int color, t_coordi res)
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

void		draw_sqr(t_mlx_img *image, unsigned int color, t_coordi res, t_coordi pos)
{
	t_coordi p;
	t_coordi m;

	m.x = pos.x + res.x;
	m.y = pos.x + res.y;
	p.x = 0;
	p.y = 0;
	while (p.y < m.y)
	{
		while (p.x < m.x)
		{
			put_pixel(image, 0x000000, p, res);
			p.x++;
		}
		p.y++;	
		p.x = 0;
	}
}

t_square	*alloc_sqr(void *mlx_ptr, t_coordi strt, t_coordi end)
{
	t_square	*sqr;
	t_coordi	res;

	res.x = end.x - strt.x;
	res.y = end.y - strt.y;
	if ((sqr = ft_memalloc(sizeof(t_square))) == NULL)
		return (NULL);
	if ((sqr->img = ft_memalloc(sizeof(t_mlx_img))) == NULL)
		return (NULL);
	if (!(sqr->img->img_ptr = mlx_new_image(mlx_ptr, res.x, res.y)))
		return (NULL);
	if (!(sqr->img->img = (unsigned int *)mlx_get_data_addr(
			sqr->img->img_ptr,
			&sqr->img->bpp,
			&sqr->img->size_line,
			&sqr->img->endian)))
		return (NULL);
	fill_image(sqr->img, 0x000000, res);
	sqr->strt = strt;
	sqr->end = end;
	return (sqr);
}

unsigned int col_point(int i, int max_i)
{
	t_hsvColor col;

	col.h = 196;
	col.s = 1.0;
	col.v = 1.0;
	if (i == max_i)
		return (0);
	return (hsv_to_color(col.h, col.s, fmod((i % max_i * 0.1) ,1.0)));
}

void	*sqr_renderer(void *arg)
{
	t_sqrdt		*t;
	t_coordi	p;
	t_complex	c;
	t_coordi	res;
	t_coordi	wp;

	t = arg;
	res.x = t->sqr->end.x - t->sqr->strt.x;
	res.y = t->sqr->end.y - t->sqr->strt.y;
	p.x = t->sqr->strt.x;
	p.y = t->sqr->strt.y;
	while (p.y < t->sqr->end.y)
	{
		c.i = (p.y - (HEIGHT) / 2) * t->f->zoom + t->f->strt.y;
		while (p.x < t->sqr->end.x)
		{
			wp.x = t->sqr->strt.x != 0 ? p.x % t->sqr->strt.x : p.x;
			wp.y = t->sqr->strt.y != 0 ? p.y % t->sqr->strt.y : p.y;
			c.r = (p.x - (WIDTH ) / 2) * t->f->zoom + t->f->strt.x;
			put_pixel(t->sqr->img, col_point(t->f->cp_point(t->f, c), t->f->iter), wp, res);
			p.x += 1;
		}
		p.x = 0;
		p.y += 1;
	}
	pthread_exit(NULL);
}

t_square	**cr_squares(void *mlx_ptr)
{
	t_square	**sqrs;

	if (!(sqrs = ft_memalloc(sizeof(t_square) * 8)))
		return (NULL);
	if (!(sqrs[0] = alloc_sqr(mlx_ptr, set_coordi(0, 0), set_coordi(WIDTH / 4, HEIGHT / 2))))
		return (NULL);
	if (!(sqrs[1] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4, 0), set_coordi(WIDTH / 2, HEIGHT / 2))))
		return (NULL);
	if (!(sqrs[2] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 2, 0), set_coordi((WIDTH / 4) * 3, HEIGHT / 2))))
		return (NULL);
	if (!(sqrs[3] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4 * 3, 0), set_coordi(WIDTH, HEIGHT / 2))))
		return (NULL);
	if (!(sqrs[4] = alloc_sqr(mlx_ptr, set_coordi(0, HEIGHT / 2), set_coordi(WIDTH / 4, HEIGHT))))
		return (NULL);
	if (!(sqrs[5] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4, HEIGHT / 2), set_coordi(WIDTH / 2, HEIGHT))))
		return (NULL);
	if (!(sqrs[6] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 2, HEIGHT / 2), set_coordi(WIDTH / 4 * 3, HEIGHT))))
		return (NULL);
	if (!(sqrs[7] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4 * 3, HEIGHT / 2), set_coordi(WIDTH, HEIGHT))))
		return (NULL);
	return (sqrs);
}

int		render_fractal(t_env *env, t_fractal *f)
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
		mlx_destroy_image(env->mlx_ptr, dt[i].sqr->img->img_ptr);
		free(sqrs[i]);
		i++;
	}
	free(sqrs);
	return (1);
}




int	render_sqr(t_square *sqr, t_fractal *f)
{
	t_coordi	p;
	t_complex	c;
	t_coordi	res;
	t_coordi	wp;

	res.x = sqr->end.x - sqr->strt.x;
	res.y = sqr->end.y - sqr->strt.y;
	p.x = sqr->strt.x;
	p.y = sqr->strt.y;
	while (p.y < sqr->end.y)
	{
		c.i = (p.y - (HEIGHT ) / 2) * f->zoom + f->strt.y;
		while (p.x < sqr->end.x)
		{
			wp.x = p.x < res.x ? p.x : p.x - res.x;
			wp.y = p.y < res.y ? p.y : p.y - res.y;
			c.r = (p.x - (WIDTH ) / 2) * f->zoom + f->strt.x;
			put_pixel(sqr->img, col_point(f->cp_point(f, c), f->iter), wp, res);
			p.x += 1;
		}
		p.x = 0;
		p.y += 1;
	}
	return (0);
}
