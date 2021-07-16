/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 02:39:28 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 04:47:03 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_sort(t_stack *info)
{
	int	i = 0;
	t_node *stack_a = info[0].top;
	t_node *stack_b = info[1].top;
	
	printf("\nstack\n");
	printf("--------------------------\n");
	while (stack_a || stack_b)
	{
		printf("[%2d]\t|", i);
		if (stack_a)
		{
			printf("\t%2d", stack_a->num);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t");
		if (stack_b)
		{
			printf("\t%2d", stack_b->num);
			stack_b = stack_b->next;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
