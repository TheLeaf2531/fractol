/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 02:23:17 by vboissel          #+#    #+#             */
/*   Updated: 2018/08/18 12:56:51 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coordi	set_coordi(int x, int y)
{
	return ((t_coordi){x, y});
}

t_hsvColor	hsv_valid(float h, float s, float v)
{
	t_hsvColor hsv;

	hsv.h = fmod(h, 360);
	hsv.s = s < 0 ? 0 : s;
	hsv.s = s > 1 ? 1 : s;
	hsv.v = v < 0 ? 0 : v;
	hsv.v = v > 1 ? 1 : v;
	return (hsv);
}

static unsigned int		to_color(float r, float g,
	float b)
{
	unsigned int argb;
	unsigned int a;
	unsigned int t_0;
	unsigned int t_1;
	unsigned int t_2;

	t_0 = r;
	t_1 = g;
	t_2 = b;
	//printf("r : %d, g : %d, b : %d\n", t_0, t_1, t_2);
	a = 1;
	argb = (
		(((a > 0xff) ? 0xff : a) << 24) |
		(((r > 0xff) ? 0xff : t_0) << 16) |
		(((g > 0xff) ? 0xff : t_1) << 8) |
		(((b > 0xff) ? 0xff : t_2)));
	return (argb);
}


unsigned int			hsv_to_color(float h, float s, float v)
{
	unsigned int rgb;
	float c;
	float x;
	float m;

	c = v * s;
	x = c * (1 - fabs(fmod(h/60.0, 2.0) - 1));
	m = v - c;
	if (h <= 60)
		return (to_color((c + m) * 255, (x + m) * 255,m * 255));
	else if (h <= 120)
		return (to_color((x + m) * 255, (c + m) * 255,m * 255));
	else if (h <= 180)
		return (to_color(m * 255, (c + m) * 255, (x + m) * 255));
	else if (h <= 240)
		return (to_color(m * 255, (x + m) * 255, (c + m) * 255));
	else if (h <= 300)
		return (to_color((x + m) * 255,m * 255 , (c + m) * 255));
	else if (h <= 360)
		return (to_color((c + m) * 255,m * 255 , (x + m) * 255));
	return (0);
}