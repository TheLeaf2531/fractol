/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:46:20 by vboissel          #+#    #+#             */
/*   Updated: 2017/12/10 19:14:20 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_strsplitlst(char const *s, char c)
{
	char	**tab;
	size_t	i;
	t_list	*start;
	t_list	*lst;
	t_list	*n;

	if ((tab = ft_strsplit(s, c)) == NULL)
		return (NULL);
	lst = ft_lstnew(tab[0], ft_strlen(tab[0]));
	start = lst;
	i = 1;
	while (tab[i])
	{
		n = ft_lstnew(tab[i], ft_strlen(tab[i]));
		ft_lstadd(&n, lst);
		lst = lst->next;
		i++;
	}
	ft_memdel((void *)tab);
	return (start);
}
