/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 04:21:57 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/08 04:24:11 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// flag 1
int	check_sort(t_node *stack, int flag)
{
	if (!stack)
		return (0);
	if (flag)
	{
		while (stack->next)
		{
			if (stack->num > stack->next->num)
				return (0);
			stack = stack->next;
		}
	}
	else
	{
		while (stack->next)
		{
			if (stack->num < stack->next->num)
				return (0);
			stack = stack->next;
		}
	}
	
	return (1);
}