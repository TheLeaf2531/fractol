/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:57:27 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/14 17:56:25 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dst_end = i;
	while (size != 0 && i < size - 1 && src[i - dst_end] != '\0')
	{
		dst[i] = src[i - dst_end];
		i++;
	}
	if (size != 0 && i < size)
		dst[i] = '\0';
	return (dst_end + ft_strlen(src));
}
