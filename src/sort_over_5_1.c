/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:18:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 23:35:03 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int arr[], int n)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i + 1 < n)
	{
		j = i;
		while (++j < n)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void	find_pivot(int flag, int pivot[], t_node *stack, int n)
{
	int		i;
	int		*arr;

	arr = (int *)ft_calloc(n, sizeof(int));
	i = -1;
	while (++i < n)
	{
		arr[i] = stack->num;
		stack = stack->next;
	}
	sort_arr(arr, n);
	if (!flag)
	{
		pivot[0] = arr[(n / 3) *2];
		pivot[1] = arr[n / 3];
	}
	else
	{
		pivot[0] = arr[n / 3];
		pivot[1] = arr[(n / 3) *2];
	}
	free(arr);
	arr = NULL;
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
	find_pivot(0, pivot, info[0].top, n);
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
