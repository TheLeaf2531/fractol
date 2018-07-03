/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:25:02 by vboissel          #+#    #+#             */
/*   Updated: 2018/07/03 16:11:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 720
# define HEIGHT 720
# define ITER 160

typedef union	u_color
{
	unsigned int	c;
	unsigned char	rgba[4];
}				t_color;

typedef struct	s_image
{
	void			*img_ptr;
	unsigned int	*img;
	int				bpp;
	int				size_line;
	int				endian;
}				t_image;

typedef struct s_complex
{
	long double r;
	long double i;
}				t_complex;

typedef struct	s_fractal
{
	long double	x1;
	long double	x2;
	long double	y1;
	long double	y2;
	t_complex	c;
	long double	zoom_x;
	long double zoom_y;
	long double zoom;
	int			(*f)(struct s_fractal *f, int x, int y);
}				t_fractal;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
	t_fractal	*f;
}				t_env;


t_fractal		*get_julia(void);
int				cp_julia(struct s_fractal *f, int x, int y);

t_fractal		*get_mandel(void);
int				cp_mandelbrot(struct s_fractal *f, int x, int y);

t_fractal		*get_newton(void);
int				cp_newton(struct s_fractal *f, int x, int y);

int				expose_hook(void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				key_hook(int keycode, void *param);

int				draw_fractal(t_env *e, t_fractal *f);
t_image			*create_image(t_env *e);
unsigned int	to_color(unsigned int r, unsigned int g,
					unsigned int b, unsigned int a);
void			put_pixel(t_image *image,
					unsigned int color, int x, int y);


void			display_pos(t_env *e);

#endif
