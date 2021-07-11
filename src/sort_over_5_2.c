/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:23:58 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/12 06:12:57 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (info[1].size && info[1].top->num < pivot[1])
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
	int	pivot[2];	// [0] small [1] big
	int	*op;
	int	i;

	printf(G);
	if (n < 3)
	{
		if (!info[1].size)
			return (info);
		if (info[1].size != 1
			&& info[1].top->num < info[1].top->next->num)
			swap(1, info[1].top);
		i = -1;
		while (++i < n)
			info = push_a(info);
		print_sort(info);
		return (info);
	}
	pivot[0] = info[1].top->num;	
	pivot[1] = info[1].top->next->num;
	if (pivot[0] > pivot[1])
	{
		pivot[0] = info[1].top->next->num;
		pivot[1] = info[1].top->num;
	}
	printf("pivot | %d %d\n", pivot[0], pivot[1]);
	op = (int *)ft_calloc(3, sizeof(int));
	i = -1;
	while (++i < n && info[1].size)
		info = sort_b(info, op, pivot);
	print_sort(info);
	printf(RESET);
	info = stack_a(info, op[2] - op[0]);	//[3] pa - ra
	set_stack(&info, op[0], op[1]);
	print_sort(info);
	info = stack_a(info, op[0]);			//[2] ra
	info = stack_b(info, op[1]);			//[1] rb
	free(op);
	return (info);
}