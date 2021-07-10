/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:18:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/09 15:12:29 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pivot_max(t_node *stack, int n)
{
	int		max;
	int		i;

	max = 0;
	i = -1;
	while (++i < n)
	{
		if (max < stack->num)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

static int	check_dist(t_node *stack, int n)
{
	int	loc1;
	int	loc2;
	int	cnt;

	cnt = 0;
	loc1 = 0;
	loc2 = 0;
	while (stack->next)
	{
		if (stack->num == n)
			loc1 = cnt;
		cnt++;
		stack = stack->next;
	}
	cnt = 0;
	while (stack->pre)
	{
		if (stack->num == n)
			loc2 = cnt;
		cnt++;
		stack = stack->pre;
	}
	printf("loc %d %d\n", loc1, loc2);
	return (loc1 - loc2);
}

static void	set_part(char f, t_stack *info[], int pivot)
{
	t_node	*stack;
	int		ret;
	
	if (f == 'a')
		stack = *info;
	else
		stack = *info + 1;

	while (stack != pivot)
	{
		ret = check_dist(info->top, pivot);
		if (ret > 0)
			rotate(f, info);
		else if (ret < 0)
			reverse_roatate(f, info);
		get_info_val(info, (info)
		print_sort(info);
	}
}

static void	sort_up(t_stack *info[], int pivot[], int op[])
{
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = *info;
	stack2 = *info + 1;
	if (stack1->top->num >= pivot[0])
	{
		rotate('a', stack1);
		op[0]++;
	}
	else
	{
		p('b', &stack1->top, &stack2->top);
		op[2]++;
		get_info_val(info, (*info)[0].top, (*info)[1].top);
		print_sort(*info);
		if (stack2->top->num <= pivot[1])
		{
			rotate('b', stack1);
			op[1]++;
		}
	}
	get_info_val(info, (*info)[0].top, (*info)[1].top);
	print_sort(*info);
}

void	sort_a(t_stack *info, int n)
{
	int pivot[2]; // max
	int	op[3];
	int	i;
	
	printf(R);
	if  (n <= 3)
		return ;
	pivot[0] = pivot_max(info[0].top, n);
	if (info[0].top->num == pivot[0])
		rotate('a', &info[0]);
	p('b', &info[0].top, &info[1].top);
	get_info_val(&info, info[0].top, info[1].top);
	pivot[1] = info[1].top->num;
	print_sort(info);

	i = -1;
	while (++i < 2)
		sort_up(&info, pivot, op);
	set_part('a', &info, pivot[1]);
	get_info_val(&info, info[0].top, info[1].top);
	printf(RESET);
}

void	sort_over_5(t_stack *info)
{
	sort_a(info, info[0].size);
}
