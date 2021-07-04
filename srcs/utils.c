/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:58:08 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/05 04:53:35 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 5);
	exit(0);
}

void	print(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	free_once(char *s)
{
	free(s);
	s = NULL;
}

void	free_double(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

void	get_info_val(t_stack **info, t_node *stack_a, t_node *stack_b)
{
	t_stack	*tmp;
	t_node	*stack;
	int	i;

	tmp = *info;
	i = -1;
	while (++i < 2)
	{
		if (!i)
			stack = stack_a;
		else
			stack = stack_b;
		if (stack)
		{
			tmp[i].size = 1;
			while (stack->pre)
				stack = stack->pre;
			tmp[i].top = stack;
			while (stack->next)
			{
				stack = stack->next;
				tmp[i].size++;
			}
			tmp[i].bot = stack;
		}
	}
}