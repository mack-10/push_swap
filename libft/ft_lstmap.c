/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:31:43 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 03:14:19 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		ft_lstdelone(new_lst, del);
	tmp = new_lst;
	while (lst->next)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
			ft_lstclear(&new_lst, del);
		new_lst->next = node;
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (tmp);
}
