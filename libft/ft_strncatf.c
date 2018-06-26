/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncatf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:09:36 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/24 19:10:16 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncatf(char *s1, char *s2)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(size);
	str = ft_strncat(str, s1, size);
	str = ft_strncat(str, s2, size);
	free(s1);
	free(s2);
	return (str);
}
