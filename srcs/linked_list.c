/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:12:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 00:46:45 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int num)
{
	t_node *new_node;

	new_node = ft_calloc(1, sizeof(t_node));
	new_node->num = num;
	new_node->pre = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_lst_node(t_node **lst, int num)
{
	t_node	*new;
	t_node	*pre;
	
	new = new_node(num);
	pre = *lst;
	(*lst)->next = new;
	*lst = (*lst)->next;
	(*lst)->pre = pre;
}