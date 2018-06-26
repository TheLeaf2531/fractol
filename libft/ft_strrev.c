/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:09:15 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/17 17:52:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	y;
	char	temp_c;

	if (!str)
		return (NULL);
	i = 0;
	y = ft_strlen(str) - 1;
	while (i < y)
	{
		temp_c = str[i];
		str[i] = str[y];
		str[y] = temp_c;
		i++;
		y--;
	}
	return (str);
}
