/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:19:02 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/21 21:07:01 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *temp_list;

	if (lst == NULL)
		return ;
	temp_list = lst;
	while (temp_list)
	{
		(*f)(temp_list);
		temp_list = temp_list->next;
	}
}
