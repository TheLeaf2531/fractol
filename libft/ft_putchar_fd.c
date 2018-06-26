/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:15:33 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/27 20:25:18 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	temp_c;
	unsigned char	*tmp;
	size_t			i;

	temp_c = (unsigned char)c;
	if (temp_c <= 127)
		write(fd, &temp_c, 1);
	else
	{
		i = 0;
		tmp = ft_to_utf8(temp_c);
		while (tmp[i])
		{
			write(fd, &tmp[i], 1);
			i++;
		}
	}
}
