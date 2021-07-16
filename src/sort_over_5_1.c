/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:18:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/16 23:20:01 by sujeon           ###   ########.fr       */
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

static int	*set_pivot(t_node *stack, int n)
{
	int	i;
	int	max;

	i = 0;
	max = stack->num;
	while (++i < n)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

t_stack	*stack_a(t_stack *tmp, int n)
{
	int	pivot[2];	// [0] big [1] small
	int	op[3];		// operation count ra rb pa,pb
	int	i;
	t_stack	*info;

	info = get_info_val(tmp[0].top, tmp[1].top);
	free(tmp);
	tmp = NULL;
	if (n < 3)
	{
		if (info[0].size != 1
			&& info[0].top->num > info[0].top->next->num)
			swap(0, info[0].top);
		return (info);
	}
	pivot[0] = info[0].bot->num;	
	pivot[1] = info[0].top->num;
	if (pivot[0] < pivot[1])
	{
		while (pivot[0] < pivot[1])
		{
			pivot[0] = info[0].top->next->num;
			pivot[1] = info[0].top->num;	
		}
		
	}
	printf("pivot | %d %d\n", pivot[0], pivot[1]);
	i = -1;
	while (++i < 3)
		op[i] = 0;
	i = -1;
	while (++i < n && info[0].size != 1)
		info = sort_a(info, op, pivot);
	set_stack(&info, op[0], op[1]);
	info = stack_a(info, op[0]);			//[3]
	info = stack_b(info, op[1]);			//[2]
	info = stack_b(info, op[2] - op[1]);	//[1]
	return (info);
}

void	sort_over_5(t_stack *info)
{
	info = stack_a(info, info[0].size);
	del_list(info[0].top);
	free(info);
	info = NULL;
	// print_sort(info);
}