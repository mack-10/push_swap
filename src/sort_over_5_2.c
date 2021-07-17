/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 00:23:58 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 23:27:36 by sujeon           ###   ########.fr       */
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

static t_stack	*sort_b(t_stack *tmp, int *op, int pivot[])
{
	t_stack	*info;

	info = get_info_val(tmp[0].top, tmp[1].top);
	if (info[1].top->num <= pivot[0])
	{
		info = rotate_1(1, info);
		op[1]++;
	}
	else
	{
		info = push_a(info);
		op[2]++;
		if (info[1].top && info[0].top->num < pivot[1])
		{
			info = rotate_1(0, info);
			op[0]++;
		}
	}
	free(tmp);
	tmp = NULL;
	return (info);
}

static t_stack	*n_smaller_than_3(t_stack *info, int n)
{
	int	i;

	if (!info[1].size)
		return (info);
	if (info[1].size != 1
		&& info[1].top->num < info[1].top->next->num)
		swap(1, info[1].top);
	i = -1;
	while (++i < n)
		info = push_a(info);
	return (info);
}

t_stack	*stack_b(t_stack *tmp, int n)
{
	int		pivot[2];
	int		*op;
	int		i;
	t_stack	*info;

	info = get_info_val(tmp[0].top, tmp[1].top);
	free(tmp);
	tmp = NULL;
	if (n < 3)
		return (n_smaller_than_3(info, n));
	find_pivot(1, pivot, info[1].top, n);
	op = (int *)ft_calloc(3, sizeof(int));
	i = -1;
	while (++i < n && info[1].size)
		info = sort_b(info, op, pivot);
	info = stack_a(info, op[2] - op[0]);
	set_stack(&info, op[0], op[1]);
	info = stack_a(info, op[0]);
	info = stack_b(info, op[1]);
	free(op);
	op = NULL;
	return (info);
}
