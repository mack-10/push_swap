/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:23:04 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 03:24:49 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_node *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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

static void	move(int flag, t_stack *info, t_node *stack)
{
	if (!flag)
	{
		if (stack->num < stack->next->num)
			stack = r('a', info);
		else if (stack->num > stack->next->num)
			s('a', stack);
	}
	else
	{
		if (stack->num < stack->next->num)
			stack = rr('a', info);
		else if (stack->num > stack->next->num)
			s('a', stack);
	}
	get_info_val(&info, stack, NULL);
}	

void	sort_five(t_stack *info, t_node *stack)
{
	int	max;
	int	cnt;
	int	flag;

	cnt = 0;
	max = find_max(stack);
	flag = 0;
	while (!check_sort(stack))
	{
		if (stack->next->num == max && info->size < 5)
			flag = 1;
		if ((stack->num == max || stack->next->num == max
				|| stack->next->next->num == max) && info->size == 5)
			flag = 1;
		move(flag, &info[0], stack);
		stack = info->top;
		if (info[0].bot->num == max)
			flag = 0;
		cnt++;
	}
}
