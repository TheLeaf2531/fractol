/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:29:21 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/26 20:52:57 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				i;
	long				sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == ' ') && str[i])
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + str[i++] - '0';
		if (result > 9223372036854775807)
			return (sign == 1 ? -1 : 0);
	}
	return (result * sign);
}
