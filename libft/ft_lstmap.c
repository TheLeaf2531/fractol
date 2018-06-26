/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:16:49 by vboissel          #+#    #+#             */
/*   Updated: 2017/11/22 18:07:48 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *t;
	t_list *n;
	t_list *z;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	t = (*f)(lst);
	if ((n = ft_lstnew(t->content, t->content_size)) == NULL)
		return (NULL);
	z = n;
	lst = lst->next;
	while (lst)
	{
		t = (*f)(lst);
		if ((n->next = ft_lstnew(t->content, t->content_size)) == NULL)
			return (NULL);
		n = n->next;
		lst = lst->next;
	}
	return (z);
}
