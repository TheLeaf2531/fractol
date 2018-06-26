/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:47:54 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/28 15:36:50 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *temp_s;
	char temp_c;

	temp_s = (char *)s;
	temp_c = c;
	if (n == 0)
		return (temp_s);
	while (n--)
	{
		*temp_s++ = temp_c;
	}
	return (s);
}
