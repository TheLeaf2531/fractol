/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:24:17 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/15 16:41:38 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;
	size_t	y;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if ((str = (char*)malloc(size_s1 + size_s2 + 1)) == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (size_s1--)
		str[i++] = s1[y++];
	y = 0;
	while (size_s2--)
		str[i++] = s2[y++];
	str[i] = 0;
	return (str);
}
