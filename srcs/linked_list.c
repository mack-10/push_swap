/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:12:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/02 21:29:46 by sujeon           ###   ########.fr       */
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

t_stack			*create_info(t_node *stack)
{
	t_stack	*info;

	info = ft_calloc(1, sizeof(t_stack));
	info->top = stack;
	info->size = 1;
	while (stack->next)
	{
		info->size++;
		stack = stack->next;
	}
	info->bottom = stack;
	printf("size: %d\n", info->size);
	printf("top: %d\nbottom: %d\n", info->top->num, info->bottom->num);
	printf("--------------------------\n\n");
	return (info);
}

t_node			*create_stack_a(char **src)
{
	t_node	*stack;
	t_node	*top;
	int		i;

	i = -1;
	while (src[++i])
	{
		if (!i)
		{
			stack = new_node(ft_atoi(src[i]));
			top = stack;
		}
		else
			stack = add_node(stack, ft_atoi(src[i]));
	}
	stack = top;
	return (stack);
}