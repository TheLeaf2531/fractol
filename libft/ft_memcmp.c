/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:47:18 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/11 14:25:01 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *temp_s1;
	const unsigned char *temp_s2;

	temp_s1 = s1;
	temp_s2 = s2;
	while (n--)
	{
		if (*temp_s1++ != *temp_s2++)
		{
			return (temp_s1[-1] - temp_s2[-1]);
		}
	}
	return (0);
}
