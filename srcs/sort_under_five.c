/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:23:04 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/02 00:43:25 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_node *lst)
{
	while (lst->next)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	quick_sort(t_stack *info, t_node *stack, t_node *pivot)
{
	print(info->top);
	
	if (stack_a->num < pivot->num)
		swap(stack_a, pivot, 'a');
	else
		push(stack_b, pivot, 'b');

	// 재귀 종료 조건
	if (check_sort(info->top))
	{
		print(info->top);
		return (1);
	}
	else
	{
		lst = lst->next;
		quick_sort(info, lst, pivot);
	}
		
	return (0);
}

void		sort_under_five(t_stack *info, t_node *stack_a)
{
	t_node	*pivot;
	t_node	*stack_b;

	pivot = stack_a;
	stack_b = NULL;
	stack_a = stack_a->next;
	quick_sort(info, stack_a, pivot);
	write(1, "Well Done\n", 10);
}