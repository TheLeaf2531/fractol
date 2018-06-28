/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:24:50 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/28 18:24:40 by vboissel         ###   ########.fr       */
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

void		display_pos(t_env *e)
{
	char output[50];

	snprintf(output, 50, "%Lf", e->f->x1);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 0, to_color(255, 255, 255, 0), output);
	snprintf(output, 50, "%Lf", e->f->x2);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 20, to_color(255, 255, 255, 0), output);
	snprintf(output, 50, "%Lf", e->f->y1);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 40, to_color(255, 255, 255, 0), output);
	snprintf(output, 50, "%Lf", e->f->y2);
	mlx_string_put(e->mlx_ptr, e->win_ptr, 0, 60, to_color(255, 255, 255, 0), output);
}

t_image			*create_image(t_env *e)
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

int			draw_fractal(t_env *e, t_fractal *f)
{
	int x;
	int y;
	int i;

	//printf("Draw Fractal\n");
	f->zoom_x = WIDTH / (f->x2 - f->x1);
	f->zoom_y = HEIGHT / (f->y2 - f->y1);
	x = 0;
	y = 0;
	e->img = create_image(e);
	while (y < HEIGHT)
	{
		i = f->f(f, x, y);
		if (i == ITER)
			put_pixel (e->img, to_color(0, 0, 0, 0), x, y);
		else
			put_pixel (e->img, to_color(0, i * 255/ITER, i * 255/ITER, 0), x, y);			
		y = x == WIDTH ? y + 1 : y;
		x = x == WIDTH ? 0 : x + 1; 
	}
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img->img_ptr, 0, 0);
	mlx_destroy_image(e->mlx_ptr, e->img->img_ptr);
	free(e->img);
	return (0);
}

int			key_hook(int keycode, void *param)
{
	t_env				*e;
	long double			diff_x;
	long double			diff_y;

	e = param;
	diff_x = sqrtl(powl(e->f->x2 - e->f->x1, 2.0)) * 0.1;
	diff_y = sqrtl(powl(e->f->y2 - e->f->y1, 2.0)) * 0.1;
	if (keycode == 53)
	{
		exit(0);
	}
	if (keycode == 124)
	{
		e->f->x1 += diff_x;
		e->f->x2 += diff_x;
	}
	if (keycode == 123)
	{
		e->f->x1 -= diff_x;
		e->f->x2 -= diff_x;
	}
	if (keycode == 126)
	{
		e->f->y1 -= diff_y;
		e->f->y2 -= diff_y;
	}
	if (keycode == 125)
	{
		e->f->y1 += diff_y;
		e->f->y2 += diff_y;
	}
	draw_fractal(e, e->f);
	display_pos(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, void *param)
{
	t_env				*e;
	long double			diff_x;
	long double			diff_y;

	e = param;
	(void)button;
	(void)x;
	(void)y;
	diff_x = sqrtl(powl(e->f->x2 - e->f->x1, 2.0));
	diff_y = sqrtl(powl(e->f->y2 - e->f->y1, 2.0));
	if (button == 4)
	{
		e->f->x1 += diff_x * 0.25;
		e->f->x2 -= diff_x * 0.25;
		e->f->y1 += diff_y * 0.25;
		e->f->y2 -= diff_y * 0.25;
		draw_fractal(e, e->f);
	}
	if (button == 5)
	{
		e->f->x1 -= diff_x * 0.25;
		e->f->x2 += diff_x * 0.25;
		e->f->y1 -= diff_y * 0.25;
		e->f->y2 += diff_y * 0.25;
		draw_fractal(e, e->f);
	}
	display_pos(e);
	return (0);
}

int		expose_hook(void *param)
{
	t_env *e;

	e = param;
	draw_fractal(e, e->f);
	display_pos(e);
	return (0);
}


t_env		*start_mlx()
{
	t_env	*e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (!(e->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "Fractol")))
		return (NULL);
	return (e);
}

t_fractal	*get_mandel(void)
{
	t_fractal *mandel;

	if (!(mandel = ft_memalloc(sizeof(t_fractal))))
		return (NULL);
	mandel->x1 = -0.75;
	mandel->x2 = 0.5;
	mandel->y1 = 0.0;
	mandel->y2 = 1.25;
	mandel->f = &cp_mandelbrot;
	return (mandel);
}


int			main(int argc, char **argv)
{
	t_env	*e;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr("TODO: Message d'erreur\n");
		return (0);
	}
	if (!(e = start_mlx()))
		return (0);
	if (!(e->f = get_mandel()))
		return (0);
	mlx_key_hook(e->win_ptr, &key_hook, e);
	mlx_mouse_hook(e->win_ptr, &mouse_hook, e);
	mlx_expose_hook(e->win_ptr, &expose_hook, e);
	draw_fractal(e, e->f);
	mlx_loop(e->mlx_ptr);
	return (0);
}
