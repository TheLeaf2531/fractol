/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:29:18 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/26 19:31:15 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long temp_n;

	temp_n = n;
	if (temp_n < 0)
	{
		ft_putchar_fd('-', fd);
		temp_n *= -1;
	}
	if (temp_n >= 10)
	{
		ft_putnbr_fd(temp_n / 10, fd);
		ft_putnbr_fd(temp_n % 10, fd);
	}
	if (temp_n <= 9)
		ft_putchar_fd(temp_n + '0', fd);
}
