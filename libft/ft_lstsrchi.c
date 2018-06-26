/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsrchi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:13:43 by vboissel          #+#    #+#             */
/*   Updated: 2017/12/15 21:07:49 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_lstsrchi(t_list **lst, char *s)
{
	size_t	i;
	t_list	*lst_tmp;

	i = 0;
	lst_tmp = *lst;
	while (lst_tmp != NULL && lst_tmp->content != NULL)
	{
		if (ft_strcmp(lst_tmp->content, s) == 0)
			i += 1;
		lst_tmp = lst_tmp->next;
	}
	lst_tmp = NULL;
	return (i);
}
