/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:18:37 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/08 06:19:01 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_stack *info, int n);

static int	find_pivot(t_node *stack, int n)
{
	int	pivot;
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (++i < n)
		stack = stack->next;
	pivot = stack->num;
	return (pivot);
}

static void sort_b(t_stack *info, int n)
{
	int	pivot;
	int rb;
	int pa;
	int	i;

	printf(G);
	if (n <= 1 || !info[1].top)
	{
		printf("achieve\n");
		p('a', &info[1].top, &info[0].top);
		print_sort(info);
		return ;
	}
	pivot = find_pivot(info[1].top, n);
	printf("\nn     | %d\n", n);
	printf("pivot | %d\n\n", pivot);
	rb = 0;
	pa = 0;
	i = -1;
	while (++i < n)
	{
		printf("\ni/n     | %d/%d\n", i, n);
		printf("pivot | %d\n\n", pivot);
		if (info[1].top->next
			&& info[1].top->num < info[1].top->next->num)
		{
			s('b', info[1].top);
			print_sort(info);
		}
		if (info[1].top->num < pivot)
		{
			r('b', &info[1]);
			rb++;
		}
		else
		{
			p('a', &info[1].top, &info[0].top);
			pa++;
		}
		print_sort(info);
		get_info_val(&info, info[0].top, info[1].top);
	}
	printf(RESET);
	sort_a(info, pa);
	sort_b(info, info[1].size);
}

static void sort_a(t_stack *info, int n)
{
	int	pivot;
	int ra;
	int pb;
	int	i;
	
	printf(R);
	if (n <= 1 || !info[0].top
		|| check_sort(info[0].top, 1))
		return ;
	pivot = find_pivot(info[0].top, n);
	printf("\nn     | %d\n", n);
	printf("pivot | %d\n\n", pivot);
	ra = 0;
	pb = 0;
	i = -1;
	while (++i < n && info[0].size > 1)
	{
		if (info[0].top->num > pivot)
		{
			r('a', &info[0]);
			ra++;
		}
		else
		{
			p('b', &info[0].top, &info[1].top);
			pb++;
		}
		print_sort(info);
		get_info_val(&info, info[0].top, info[1].top);
	}
	printf(RESET);
	sort_a(info, ra);
	sort_b(info, pb);
}

void	sort_over_5(t_stack *info)
{
	print_sort(info);
	sort_a(info, info[0].size);
}
