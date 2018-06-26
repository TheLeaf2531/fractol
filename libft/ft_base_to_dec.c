/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:48:29 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/22 19:05:02 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_base_valid(char *base)
{
	size_t i;
	size_t y;

	if (ft_strlen((const char*)base) <= 1)
		return (0);
	i = 0;
	y = i + 1;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[y])
		{
			if (base[i] == base[y])
				return (0);
			y++;
		}
		i++;
		y = i + 1;
	}
	return (1);
}

static int	valid_args(char *str, char *base)
{
	size_t	i;
	size_t	y;
	int		test;

	i = 0;
	y = 0;
	test = 0;
	if (!is_base_valid(base))
		return (0);
	while (i < ft_strlen(str))
	{
		while (y < ft_strlen(base))
		{
			if (str[i] == base[y] || str[i] == '-')
				test = 1;
			y++;
		}
		if (test == 0)
			return (0);
		test = 0;
		i++;
		y = 0;
	}
	return (1);
}

long		ft_base_to_dec(char *str, char *base)
{
	size_t	i;
	size_t	y;
	size_t	b_value;
	long	res;

	if (str == NULL || base == NULL)
		return (0);
	if (!valid_args(str, base))
		return (0);
	res = 0;
	i = (str[0] == '-') ? 1 : 0;
	while (i < ft_strlen(str))
	{
		b_value = 0;
		y = 0;
		while (y < ft_strlen(base))
		{
			b_value = (!b_value && base[y] == str[i]) ? y : b_value;
			y++;
		}
		res += b_value * ft_ipower(ft_strlen(base), ft_strlen(str) - 1 - i);
		i++;
	}
	res = (str[0] == '-') ? res * -1 : res;
	return (res);
}
