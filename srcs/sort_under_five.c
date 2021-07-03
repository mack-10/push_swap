/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:23:04 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/04 08:48:31 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	check_sort(t_node *lst)
// {
// 	while (lst->next)
// 	{
// 		if (lst->num > lst->next->num)
// 			return (0);
// 		lst = lst->next;
// 	}
// 	return (1);
// }

// void		set_bot_big(t_stack *info, t_node *stack)
// {
// 	int	big;
// 	int loc;
// 	int cnt;
	
// 	big = stack->num;
// 	loc = 0;
// 	cnt = 0;
// 	while (stack->next)
// 	{
// 		stack = stack->next;
// 		if (big < stack->num)
// 		{
// 			big = stack->num;
// 			loc = cnt;
// 		}
// 		cnt++;
// 	}
// 	if (info->size - loc < loc)
// 		rra
// 	else
// 		ra
// }

// void		sort(t_stack *info, t_node *stack_a, t_node *stack_b)
// {
// 	set_bot_big(info, stack_a);
// 	while (!check_sort)
// 	{

// 	}
	
// }

void		sort_under_five(t_stack *info, t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;

	s('a', stack_a);
	print_sort(stack_a);
	stack_a = r('a', info);
	print_sort(stack_a);
	stack_a = rr('a', info);
	print_sort(stack_a);
	p('b', &stack_a, &stack_b);
	print_sort(stack_a);
	print_sort(stack_b);
	// sort(info, stack_a);
}