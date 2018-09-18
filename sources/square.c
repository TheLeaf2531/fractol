/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:48:10 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 16:28:31 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_sqr(t_mlx_img *image, unsigned int color,
				t_coordi res, t_coordi pos)
{
	t_coordi p;
	t_coordi m;

	m.x = pos.x + res.x;
	m.y = pos.x + res.y;
	p.x = 0;
	p.y = 0;
	color = 0;
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

t_square	**cr_squares(void *mlx_ptr)
{
	t_square	**sqrs;

	if (!(sqrs = ft_memalloc(sizeof(t_square) * 8)))
		return (NULL);
	sqrs[0] = alloc_sqr(mlx_ptr, set_coordi(0, 0),
				set_coordi(WIDTH / 4, HEIGHT / 2));
	sqrs[1] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4, 0),
				set_coordi(WIDTH / 2, HEIGHT / 2));
	sqrs[2] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 2, 0),
				set_coordi((WIDTH / 4) * 3, HEIGHT / 2));
	sqrs[3] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4 * 3, 0),
				set_coordi(WIDTH, HEIGHT / 2));
	sqrs[4] = alloc_sqr(mlx_ptr, set_coordi(0, HEIGHT / 2),
				set_coordi(WIDTH / 4, HEIGHT));
	sqrs[5] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4, HEIGHT / 2),
				set_coordi(WIDTH / 2, HEIGHT));
	sqrs[6] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 2, HEIGHT / 2),
				set_coordi(WIDTH / 4 * 3, HEIGHT));
	sqrs[7] = alloc_sqr(mlx_ptr, set_coordi(WIDTH / 4 * 3, HEIGHT / 2),
				set_coordi(WIDTH, HEIGHT));
	return (sqrs);
}
