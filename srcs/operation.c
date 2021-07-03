/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:03:11 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/04 08:48:07 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void		s(char sign, t_node *stack)
{
	int tmp;
	
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (sign == 'a')
		print("sa");
	else
		print("sb");
}

t_node		*r(char sign, t_stack *info)
{
	t_node *ex_top;
	t_node *ex_bot;
	
	ex_top = info->top;
	ex_bot = info->bottom;
	info->top = ex_top->next;
	info->bottom = ex_top;
	info->top->pre = NULL;
	ex_bot->next = info->bottom;
	info->bottom->pre = ex_bot;
	info->bottom->next = NULL;
	if (sign == 'a')
		print("ra");
	else
		print("rb");
	return (info->top);
}

t_node		*rr(char sign, t_stack *info)
{
	t_node *ex_top;
	t_node *ex_bot;
	
	ex_top = info->top;
	ex_bot = info->bottom;
	info->top = ex_bot;
	info->bottom = ex_bot->pre;
	info->top->pre = NULL;
	info->top->next = ex_top;
	ex_top->pre = info->top;
	info->bottom->next = NULL;
	if (sign == 'a')
		print("rra");
	else
		print("rrb");
	return (info->top);
}

void		p(char sign, t_node **push, t_node **pop)
{
	if (!(*pop))
	{
		*pop = *push;
		*push = (*push)->next;
		(*push)->pre = NULL;
		(*pop)->next = NULL;
	}
	// else
	// {
	// 	while(pop->next)
	// 		pop = pop->next;
	// 	pop->next = push;
	// 	push = push->next;
	// 	push->pre = NULL;
	// 	pop->next->next = NULL;
	// }
	if (sign == 'a')
		print("pa");
	else
		print("pb");

	// print_sort(*push);
	// print_sort(*pop);
}