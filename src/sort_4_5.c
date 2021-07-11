/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:23:04 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/12 03:45:57 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_node *stack)
{
	int	max;

	max = stack->num;
	while (stack->next)
	{
		if (max < stack->next->num)
			max = stack->next->num;
		stack = stack->next;
	}
	return (max);
}

static t_stack	*sort2(t_stack *info)
{
	while (info[1].top)
	{
		if (info[1].top->num < info[0].top->num)
			info = push_a(info);
		else if (info[0].top->num < info[1].top->num
			&& info[1].top->num < info[0].top->next->num)
		{
			info = rotate_1(0, info);
			info = push_a(info);
		}
		else
			info = rotate_1(0, info);
	}
	while (!check_sort(info[0].top))
		info = rotate_1(0, info);
	return (info);
}

static t_stack	*sort1(t_stack *info)
{
	int	max;

	max = find_max(info[0].top);
	while (info[1].size != 2)
	{
		if (info[0].top->num < max)
			info = push_b(info);
		else
			info = rotate_1(0, info);
	}
	if (info[0].top->num == max)
		info = rotate_1(0, info);
	else
	{
		while (info[0].bot->num != max)
			info = reverse_rotate_1(0, info);
	}
	if (info[0].top->num > info[0].top->next->num)
		swap(0, info[0].top);
	if (info[1].top->num > info[1].top->next->num)
		swap(1, info[1].top);
	return (info);
}

void	sort_4_5(t_stack *info)
{
	info = sort1(info);
	info = sort2(info);
	del_list(info[0].top);
	free(info);
	info = NULL;
}
