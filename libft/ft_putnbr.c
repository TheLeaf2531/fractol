/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:02:26 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/26 19:28:28 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long temp_n;

	temp_n = n;
	if (temp_n < 0)
	{
		ft_putchar('-');
		temp_n *= -1;
	}
	if (temp_n >= 10)
	{
		ft_putnbr(temp_n / 10);
		ft_putnbr(temp_n % 10);
	}
	if (temp_n <= 9)
		ft_putchar(temp_n + '0');
}
