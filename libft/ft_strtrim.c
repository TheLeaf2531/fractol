/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:14:31 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/16 14:32:19 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	y;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] <= 32 && s[len - 1])
		len--;
	i = -1;
	while (s[++i] <= 32 && s[i] && len > 0)
		len--;
	if ((str = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	y = 0;
	while (y < len)
	{
		str[y] = s[i + y];
		y++;
	}
	str[y] = 0;
	return (str);
}
