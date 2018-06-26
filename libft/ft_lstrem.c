/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:15:52 by vboissel          #+#    #+#             */
/*   Updated: 2017/12/15 17:45:13 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrem(t_list **prev, t_list **to_del)
{
	t_list	*next;
	char	*test;

	if (prev != NULL && to_del != NULL)
	{
		next = (*to_del)->next;
		test = (*to_del)->content;
		ft_strdel(&test);
		(*to_del) = 0;
		ft_memdel((void *)to_del);
		(*prev)->next = next;
		next = NULL;
		test = NULL;
	}
}
