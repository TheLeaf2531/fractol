/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:03:04 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/13 11:47:31 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;
	size_t src_size;

	src_size = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		if (i < src_size)
			dest[i] = src[i];
		else
			dest[i] = 0;
		i++;
	}
	return (dest);
}
