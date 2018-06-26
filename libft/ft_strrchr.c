/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:09:10 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/21 21:26:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s_cp;

	s_cp = (char*)s;
	i = ft_strlen(s);
	while (i + 1 != 0)
	{
		if (s_cp[i] == c)
			return (&s_cp[i]);
		i--;
	}
	return (NULL);
}
