/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:12:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 04:59:49 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int num)
{
	t_node *new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	new_node->num = num;
	new_node->pre = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void		add_node(t_node **lst, int num)
{
	t_node	*new;
	t_node	*pre;
	
	new = new_node(num);
	pre = *lst;
	(*lst)->next = new;
	*lst = (*lst)->next;
	(*lst)->pre = pre;
}

t_node			*linked_lst(char **s)
{
	t_node	*lst;
	t_node	*first_node;
	int		i;

	i = -1;
	while (s[++i])
	{
		if (!i)
		{
			lst = new_node(ft_atoi(s[i]));
			first_node = lst;
		}			
		else
			add_node(&lst, ft_atoi(s[i]));
	}
	lst->next = first_node;
	first_node->pre = lst;
	lst = lst->next;
	return (lst);
}