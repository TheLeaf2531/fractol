/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_utf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:26:34 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/25 22:38:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*create_tab(unsigned char *str)
{
	size_t			i;
	size_t			size;
	unsigned char	*tab;
	char			*add;

	add = ft_strnew(8);
	size = ft_strlen((char *)str) / 6;
	size = ft_strlen((char *)str) % 6 ? size + 1 : size;
	if ((tab = (unsigned char*)ft_strnew(size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < 8)
	{
		add[i] = i < size ? '1' : '0';
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = i == 0 ? ft_base_to_dec(add, "01") : (char)128;
		i++;
	}
	tab[i] = 0;
	ft_strdel(&add);
	return (tab);
}

unsigned char			*ft_to_utf8(int nbr_dec)
{
	unsigned char	*utf_tab;
	unsigned char	*nbr_bin;
	unsigned char	*tmp_bin;
	size_t			i;
	size_t			loc_size;

	nbr_bin = (unsigned char*)ft_dec_to_base(nbr_dec, "01");
	utf_tab = create_tab(nbr_bin);
	i = 0;
	loc_size = 6 - ft_strlen((char *)nbr_bin) % 6;
	while (utf_tab[i])
	{
		if (i)
			tmp_bin = (unsigned char *)ft_strsub((char *)nbr_bin,
							i * 6 - loc_size, 6);
		else
			tmp_bin = (unsigned char *)ft_strsub((char *)nbr_bin, 0,
						6 - loc_size);
		utf_tab[i] += ft_base_to_dec((char *)tmp_bin, "01");
		i++;
	}
	ft_strdel((char **)&tmp_bin);
	ft_strdel((char **)&nbr_bin);
	return (utf_tab);
}
