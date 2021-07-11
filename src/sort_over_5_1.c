/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:18:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/12 02:01:51 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack(t_stack **info, int ra, int rb)
{
	while (ra || rb)
	{
		if (ra && rb
			&& (*info)[0].size != 1
			&& (*info)[1].size != 1)
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
		if (info[1].top->num < pivot[1])
		{
			info = rotate_1(1, info);
			op[1]++;
		}
	}
	free(tmp);
	tmp = NULL;
	return (info);
}

t_stack	*stack_a(t_stack *info, int n)
{
	int	pivot[2];
	int	*op;
	int	i;

	printf(R);
	if (n < 3)
	{
		if (info[0].size != 1 && info[0].top->num > info[0].top->next->num)
			swap(0, info[0].top);
		return (info);
	}
	while (info[0].top->num > info[0].bot->num)
		info = rotate_1(0, info);
	info = push_b(info);
	pivot[0] = info[0].bot->num;
	pivot[1] = info[1].top->num;
	printf("pivot | %d %d\n", pivot[0], pivot[1]);
	op = (int *)ft_calloc(3, sizeof(int));
	i = -1;
	while (++i < n && info[0].size != 1)
		info = sort_a(info, op, pivot);
	set_stack(&info, op[0], op[1]);
	print_sort(info);
	printf(RESET);
	free(op);
	return (info);
}

void	sort_over_5(t_stack *info)
{
	stack_a(info, info[0].size);
}
