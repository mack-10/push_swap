/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:12:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/23 23:30:25 by sujeon           ###   ########.fr       */
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

static t_node	*add_node(t_node *lst, int num)
{
	t_node	*new;
	t_node	*pre;
	
	new = new_node(num);
	pre = lst;
	lst->next = new;
	lst = lst->next;
	lst->pre = pre;
	return (lst);
}

t_node			*create_stack_a(char **s, t_stack *info)
{
	t_node	*stack;
	int		i;

	info->size = 0;
	i = -1;
	while (s[++i])
	{
		if (!i)
		{
			stack = new_node(ft_atoi(s[i]));
			info->top = stack;
		}			
		else
			stack = add_node(stack, ft_atoi(s[i]));
		info->size++;
	}
	info->bottom = stack;
	stack = info->top;
	printf("size: %d\n", info->size);
	printf("top: %d\nbottom: %d\n", info->top->num, info->bottom->num);
	return (stack);
}