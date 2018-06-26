/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:40:34 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/21 22:54:06 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *str_cp;

	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	str_cp = str;
	while (size-- + 1)
		*str++ = '\0';
	return (str_cp);
}
