/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:58:22 by vboissel          #+#    #+#             */
/*   Updated: 2018/03/06 17:13:30 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list **alst, size_t n)
{
	size_t len;
	size_t i;

	if (alst == NULL)
		return (NULL);
	i = 0;
	len = ft_lstlen(&(*alst));
	if (n > len)
		return (NULL);
	while (i != n)
	{
		alst = &(*alst)->next;
		i++;
	}
	return (*alst);
}
