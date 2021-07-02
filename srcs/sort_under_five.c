/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 22:23:04 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/02 23:33:10 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_node *lst)
{
	while (lst->next)
	{
		if (lst->num > lst->next->num)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	sort_pivot(t_node *stack, t_stack *info)
{
	t_node	*pivot = stack;
	if (stack < pivot)
		sa;
	else
		pb;
	if (check_sort(stack_a))
		
}

void		sort_under_five(t_stack *info, t_node *stack_a)
{
	t_node	*pivot;
	t_node	*stack_b;

	pivot = stack_a;
	stack_b = NULL;
	stack_a = stack_a->next;
	write(1, "Well Done\n", 10);
}