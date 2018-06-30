/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:25:02 by vboissel          #+#    #+#             */
/*   Updated: 2018/06/30 20:34:16 by vboissel         ###   ########.fr       */
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

#endif
