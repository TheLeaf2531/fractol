/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:46:27 by vboissel          #+#    #+#             */
/*   Updated: 2018/09/18 18:43:06 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <pthread.h>

# include "libft.h"
# include "mlx.h"

# define WIDTH 1280
# define HEIGHT 1000

typedef struct	s_hsvcolor
{
	float	h;
	float	s;
	float	v;
}				t_hsvcolor;

typedef	struct	s_rgbcolor
{
	int		r;
	int		g;
	int		b;
}				t_rgbcolor;

typedef struct	s_mlx_img
{
	void			*img_ptr;
	unsigned int	*img;
	int				bpp;
	int				size_line;
	int				endian;
}				t_mlx_img;

typedef struct	s_coordi
{
	int x;
	int y;
}				t_coordi;

typedef struct	s_coordld
{
	long double x;
	long double y;
}				t_coordld;

typedef struct	s_complex
{
	long double r;
	long double i;
}				t_complex;

typedef struct	s_fractal
{
	t_coordld	strt;
	t_coordld	end;
	long double	zoom;
	t_complex	c;
	float		col;
	int			iter;
	int			(*cp_point)(struct s_fractal *f, t_complex c);
}				t_fractal;

typedef struct	s_square
{
	t_coordi	strt;
	t_coordi	end;
	t_mlx_img	*img;
}				t_square;

typedef struct	s_renderer
{
	t_fractal	*f;
	t_square	**squares;
}				t_renderer;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_fractal	*f;
}				t_env;

typedef	struct	s_sqrdt
{
	t_square		*sqr;
	t_fractal		*f;
	pthread_mutex_t	mutex;
}				t_sqrdt;

void			put_pixel(t_mlx_img *image, unsigned int color,
							t_coordi p, t_coordi res);
void			fill_image(t_mlx_img *image, unsigned int color, t_coordi res);
t_square		*alloc_sqr(void *mlx_ptr, t_coordi strt, t_coordi end);
int				render_sqr(t_square *sqr, t_fractal *f);
void			*sqr_renderer(void *arg);
t_square		**cr_squares(void *mlx_ptr);
int				render_fractal(t_env *env, t_fractal *f);
int				cp_mandelbrot(struct s_fractal *f, t_complex c);
t_fractal		*get_mandel_properties(void);
int				cp_julia(struct s_fractal *f, t_complex c);
t_fractal		*get_julia_properties(void);
int				cp_burning(struct s_fractal *f, t_complex c);
t_fractal		*get_burning_properties(void);
t_coordi		set_coordi(int x, int y);
unsigned int	hsv_to_color(float h, float s, float v);
void			sqrdel(t_env *env, t_sqrdt *dt, t_square **sqrs);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				house_move_hook(int x, int y, void *param);
int				close_hook(void *param);
int				key_pressed_hook(int keycode, void *param);

#endif
