/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:25:26 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/18 13:43:22 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_ipower(long nbr, long pwr)
{
	if (pwr < 0)
		return (0);
	if (pwr == 0)
		return (1);
	if (pwr == 1)
		return (nbr);
	if (nbr * nbr > 2147483647)
		return (0);
	if (pwr > 0)
		return (nbr * ft_ipower(nbr, pwr - 1));
	return (0);
}
