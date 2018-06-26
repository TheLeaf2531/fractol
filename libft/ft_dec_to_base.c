/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:40:21 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/23 18:58:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		calc_str_size(long nbr, size_t base_l)
{
	size_t str_size;

	nbr = nbr < 0 ? nbr * -1 : nbr;
	str_size = 0;
	while (ft_ipower(base_l, str_size) - 1 < nbr)
	{
		str_size++;
	}
	return (str_size);
}

static int			is_base_valid(const char *base)
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

static char			*convert_to_base(size_t nbr, const char *base, char *str)
{
	size_t base_size;

	base_size = ft_strlen(base);
	if (nbr >= base_size)
	{
		convert_to_base(nbr % base_size, base, str);
		convert_to_base(nbr / base_size, base, str + 1);
	}
	else
		*str = base[nbr];
	return (str);
}

char				*ft_dec_to_base(long nbr, const char *base)
{
	char	*str_base;
	char	*str_cp;
	size_t	base_size;
	size_t	str_size;

	if (!is_base_valid(base))
		return (NULL);
	base_size = ft_strlen(base);
	str_size = calc_str_size(nbr, base_size);
	str_size = nbr < 0 ? str_size + 1 : str_size;
	if ((str_base = ft_strnew(str_size + 1)) == NULL)
		return (NULL);
	str_cp = str_base;
	if (nbr < 0)
	{
		nbr = nbr < 0 ? nbr * -1 : nbr;
		*str_base = '-';
		str_base += 1;
	}
	str_base = convert_to_base(nbr, base, str_base);
	str_base = ft_strrev(str_base);
	return (str_cp);
}
