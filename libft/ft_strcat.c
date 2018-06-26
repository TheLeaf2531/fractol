/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:55:07 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/10 19:09:06 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t size_concat;
	size_t i;

	i = ft_strlen(s1);
	size_concat = i + ft_strlen(s2);
	while (i < size_concat)
		s1[i++] = *s2++;
	s1[i] = 0;
	return (s1);
}
