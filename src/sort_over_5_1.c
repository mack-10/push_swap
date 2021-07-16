/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:18:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 01:55:53 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack(t_stack **info, int ra, int rb)
{
	while (ra || rb)
	{
		if (ra && rb
			&& (*info)[0].size > 2
			&& (*info)[1].size > 2)
		{
			*info = reverse_rotate_1(2, *info);
			ra--;
			rb--;
		}
		else if (ra)
		{
			*info = reverse_rotate_1(0, *info);
			ra--;
		}
		else if (rb)
		{
			*info = reverse_rotate_1(1, *info);
			rb--;
		}
	}
}

static t_stack	*sort_a(t_stack *tmp, int *op, int pivot[])
{
	t_stack	*info;

	info = get_info_val(tmp[0].top, tmp[1].top);
	if (info[0].top->num >= pivot[0])
	{
		info = rotate_1(0, info);
		op[0]++;
	}
	else
	{
		info = push_b(info);
		op[2]++;
		if (info[1].top->num >= pivot[1])
		{
			info = rotate_1(1, info);
			op[1]++;
		}
	}
	free(tmp);
	tmp = NULL;
	return (info);
}

void	set_pivot(int flag, int pivot[], t_node *stack)
{
	pivot[0] = stack->num;
	pivot[1] = stack->next->num;
	if (!flag && pivot[0] < pivot[1])
	{
		pivot[0] = stack->next->num;
		pivot[1] = stack->num;
	}
	if (flag && pivot[0] > pivot[1])
	{
		pivot[0] = stack->next->num;
		pivot[1] = stack->num;
	}
}

static t_stack	*n_smaller_than_3(t_stack *info)
{
	if (info[0].size != 1
		&& info[0].top->num > info[0].top->next->num)
		swap(0, info[0].top);
	return (info);
}

t_stack	*stack_a(t_stack *tmp, int n)
{
	int		pivot[2];
	int		*op;
	int		i;
	t_stack	*info;

	info = get_info_val(tmp[0].top, tmp[1].top);
	free(tmp);
	tmp = NULL;
	if (n < 3)
		return (n_smaller_than_3(info));
	set_pivot(0, pivot, info[0].top);
	op = (int *)ft_calloc(3, sizeof(int));
	i = -1;
	while (++i < n && info[0].size != 1)
		info = sort_a(info, op, pivot);
	set_stack(&info, op[0], op[1]);
	info = stack_a(info, op[0]);
	info = stack_b(info, op[1]);
	info = stack_b(info, op[2] - op[1]);
	free(op);
	op = NULL;
	return (info);
}
