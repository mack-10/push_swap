/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:29:30 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 04:28:47 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move(t_node **push, t_node **pop)
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

t_stack	*push_b(t_stack *tmp)
{
	t_node	*push;
	t_node	*pop;
	t_stack	*info;

	push = tmp[0].top;
	pop = tmp[1].top;
	if (!push)
		return (tmp);
	else
	{
		move(&push, &pop);
		info = get_info_val(push, pop);
		print("pb\n");
	}
	free(tmp);
	tmp = NULL;
	return (info);
}

t_stack	*push_a(t_stack *tmp)
{
	t_stack	*info;
	t_node	*push;
	t_node	*pop;

	push = tmp[1].top;
	pop = tmp[0].top;
	if (!push)
		return (tmp);
	else
	{
		move(&push, &pop);
		info = get_info_val(pop, push);
		print("pa\n");
	}
	free(tmp);
	tmp = NULL;
	return (info);
}
