/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:03:14 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/14 19:01:10 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h_cp;
	size_t	i;
	size_t	n;
	size_t	c;

	h_cp = (char *)haystack;
	i = 0;
	n = 0;
	c = 0;
	if (ft_strlen(needle) == 0)
		return (h_cp);
	while (n < ft_strlen(haystack) && needle)
	{
		while (i < ft_strlen(haystack) && i < len)
		{
			c = (haystack[i] == needle[c]) ? c + 1 : 0;
			i++;
			if (c == ft_strlen(needle))
				return (&h_cp[i - ft_strlen(needle)]);
		}
		c = 0;
		n++;
		i = n;
	}
	return (NULL);
}
