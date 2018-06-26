/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:12:24 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/27 20:29:25 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putchar(char c)
{
	unsigned char	temp_c;
	unsigned char	*tmp;
	size_t			i;

	temp_c = (unsigned char)c;
	if (temp_c <= 127)
		write(1, &temp_c, 1);
	else
	{
		i = 0;
		tmp = ft_to_utf8(temp_c);
		while (tmp[i])
		{
			write(1, &tmp[i], 1);
			i++;
		}
	}
}
