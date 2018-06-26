/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:00:18 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/24 14:39:31 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenc(const char *str, char c)
{
	size_t size;

	if (str == NULL)
		return (0);
	size = 0;
	while (str[size] != c && str[size])
		size++;
	return (size);
}
