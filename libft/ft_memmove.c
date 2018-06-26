/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:48:13 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/28 16:15:54 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	size_t			i;

	i = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst > temp_src)
	{
		while (len--)
			temp_dst[len] = temp_src[len];
	}
	else if (temp_dst < temp_src)
	{
		while (len--)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
