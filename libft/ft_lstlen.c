/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:08:53 by vboissel          #+#    #+#             */
/*   Updated: 2018/02/24 19:02:34 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **alst)
{
	size_t	size;
	t_list	**temp_alst;

	if (alst == NULL)
		return (0);
	size = 0;
	temp_alst = alst;
	while ((*temp_alst)->next)
	{
		temp_alst = &(*temp_alst)->next;
		size++;
	}
	alst = temp_alst;
	return (size);
}
