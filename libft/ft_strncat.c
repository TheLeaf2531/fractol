/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:37:11 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/13 16:33:06 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size_s1;
	size_t	i;

	i = 0;
	size_s1 = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
		s1[size_s1++] = (unsigned char)s2[i++];
	s1[size_s1] = 0;
	return (s1);
}
