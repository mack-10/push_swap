/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:58:08 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 02:46:20 by sujeon           ###   ########.fr       */
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
	int	i;

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
	t_node	*stack;
	int		i;

	i = -1;
	while (++i < 2)
	{
		if (!i)
			stack = stack_a;
		else
			stack = stack_b;
		if (stack)
		{
			(*info)[i].size = 1;
			while (stack->pre)
				stack = stack->pre;
			(*info)[i].top = stack;
			while (stack->next)
			{
				stack = stack->next;
				(*info)[i].size++;
			}
			(*info)[i].bot = stack;
		}
	}
}
