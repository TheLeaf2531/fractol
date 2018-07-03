/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:03:41 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 16:04:56 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int		to_color(unsigned int r, unsigned int g,
	unsigned int b, unsigned int a)
{
	unsigned int argb;

	argb = (
		(((a > 0xff) ? 0xff : a) << 24) |
		(((r > 0xff) ? 0xff : r) << 16) |
		(((g > 0xff) ? 0xff : g) << 8) |
		(((b > 0xff) ? 0xff : b)));
	return (argb);
}

void				put_pixel(t_image *image,
						unsigned int color, int x, int y)
{
	if (y * HEIGHT + x > HEIGHT * WIDTH)
		return ;
	image->img[y * HEIGHT + x] = color;
}

void				fill_image(t_image *image, unsigned int color)
{
	size_t	img_size;
	size_t	i;

	img_size = WIDTH * HEIGHT;
	i = 0;
	while (i < img_size)
	{
		image->img[i] = color;
		i++;
	}
}

t_image			    *create_image(t_env *e)
{
	t_image	*image;

	if ((image = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if (!(image->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT)))
		return (NULL);
	if (!(image->img = (unsigned int *)mlx_get_data_addr(
			image->img_ptr,
			&image->bpp,
			&image->size_line,
			&image->endian)))
		return (NULL);
	fill_image(image, to_color(45, 0, 0, 0));
	return (image);
}

int			draw_fractal(t_env *e, t_fractal *f)
{
	int x;
	int y;
	int i;

	f->zoom_x = (long double)WIDTH / (f->x2 - f->x1);
	f->zoom_y = (long double)HEIGHT / (f->y2 - f->y1);
	x = 0;
	y = 0;
	e->img = create_image(e);
	while (y < HEIGHT)
	{
		i = f->f(f, x, y);
		if (i == ITER)
			put_pixel (e->img, to_color(0, 0, 0, 0), x, y);
		else
			put_pixel (e->img, to_color(i % 255, 0, i * 255/ITER, 0), x, y);			
		y = x == WIDTH ? y + 1 : y;
		x = x == WIDTH ? 0 : x + 1; 
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img->img_ptr, 0, 0);
	mlx_destroy_image(e->mlx_ptr, e->img->img_ptr);
	free(e->img);
	return (0);
}
