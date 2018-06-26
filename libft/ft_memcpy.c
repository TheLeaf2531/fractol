/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:03:15 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/28 15:44:40 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	temp_dst = (char *)dst;
	temp_src = (const char*)src;
	while (n--)
	{
		*temp_dst++ = *temp_src++;
	}
	return (dst);
}
