/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:18:17 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/14 18:07:41 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s_cp;
	size_t			i;
	size_t			len;

	i = 0;
	s_cp = (char*)s;
	len = ft_strlen(s);
	if (c == '\0')
		return (&s_cp[len]);
	while (i < len)
	{
		if (c == s_cp[i])
			return (&s_cp[i]);
		i++;
	}
	return (NULL);
}
