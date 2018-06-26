/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:48:44 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/28 17:50:29 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *n_list;

	if (alst == NULL || (*del) == NULL)
		return ;
	n_list = (*alst)->next;
	while (n_list)
	{
		n_list = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = n_list;
	}
	n_list = NULL;
	*alst = NULL;
}
