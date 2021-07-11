/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:23:58 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/12 01:58:46 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static t_stack	*sort_b(t_stack *tmp, int *op, int pivot[])
{
	t_stack	*info;

	info = get_info_val(tmp[0].top, tmp[1].top);
	if (info[1].top->num < pivot[0])
	{
		info = rotate_1(1, info);
		op[1]++;
	}
	else
	{
		info = push_a(info);
		op[2]++;
		if (info[1].top->num < pivot[1])
		{
			info = rotate_1(0, info);
			op[0]++;
		}
	}
	free(tmp);
	tmp = NULL;
	return (info);
}

t_stack	*stack_b(t_stack *info, int n)
{
	int	pivot[2];	// 0 min 1 max
	int	*op;
	int	i;

	printf(G);
	if (n < 3)
	{
		printf("1\n");
		if (info[1].size != 1
			&& info[1].top->num < info[1].top->next->num)
			swap(1, info[1].top);
		else
			info = push_a(info);
		print_sort(info);
		return (info);
	}
	while (info[1].top->num < info[1].bot->num)
		info = rotate_1(1, info);
	pivot[0] = info[1].bot->num;
	pivot[1] = info[1].top->num;
	printf("pivot %d %d\n", pivot[0], pivot[1]);
	op = (int *)ft_calloc(3, sizeof(int));
	i = -1;
	while (++i < n)
		info = sort_b(info, op, pivot);
	print_info(info);
	print_sort(info);
	printf(RESET);
	info = stack_a(info, op[2] - op[0]);
	set_stack(&info, op[0], op[1]);
	info = stack_a(info, op[0]);
	info = stack_b(info, op[1]);
	free(op);
	return (info);
}*/