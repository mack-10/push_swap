/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:03:11 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 04:41:50 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	move_s(t_node *stack)
{
	int	tmp;

	if (!stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

t_node	*move_r(t_node *stack)
{
	t_node	*new;
	t_node	*del;

	if (!stack->next)
		return (stack);
	new = new_node(stack->num);
	del = stack;
	stack = stack->next;
	stack->pre = NULL;
	while (stack->next)
		stack = stack->next;
	stack->next = new;
	new->pre = stack;
	free(del);
	del = NULL;
	return (stack);
}

t_node	*move_rr(t_node *stack)
{
	t_node	*new;
	t_node	*del;

	if (!stack->next)
		return (NULL);
	stack = move_end(stack);
	del = stack;
	new = new_node(stack->num);
	stack = stack->pre;
	stack->next = NULL;
	stack = move_init(stack);
	stack->pre = new;
	new->next = stack;
	stack = new;
	free(del);
	del = NULL;
	return (stack);
}

void	move_p(t_node **push, t_node **pop)
{
	t_node	*del;
	t_node	*new;

	del = *push;
	new = new_node((*push)->num);
	if (!(*pop))
		*pop = new;
	else
	{
		new->next = *pop;
		(*pop)->pre = new;
		*pop = new;
	}
	if ((*push)->next)
	{
		*push = (*push)->next;
		(*push)->pre = NULL;
	}
	else
		*push = NULL;
	free(del);
	del = NULL;
}
