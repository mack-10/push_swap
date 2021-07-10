/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 04:21:57 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/11 03:46:24 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_node *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_node	*move_end(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*move_init(t_node *stack)
{
	while (stack->pre)
		stack = stack->pre;
	return (stack);
}

void	del_list(t_node *stack)
{
	t_node	*del;

	while (stack)
	{
		del = stack;
		stack = stack->next;
		free(del);
		del = NULL;
	}
}
