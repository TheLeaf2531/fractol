/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:24:16 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/15 15:27:58 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	if ((str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
