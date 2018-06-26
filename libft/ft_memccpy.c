/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:41:23 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/28 15:54:02 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;
	size_t				i;

	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = (unsigned char)temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
