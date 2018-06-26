/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:35:37 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/12 21:54:37 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	i = 0;
	temp_s = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)temp_s[i] == (unsigned char)c)
			return (temp_s + i);
		i++;
	}
	return (NULL);
}
