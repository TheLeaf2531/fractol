/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:56:33 by vboissel          #+#    #+#             */
/*   Updated: 2017/12/08 14:52:58 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!n)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && n--)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
