/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:58:08 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/23 23:18:50 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(0);
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

void	find_top_bottom(t_node *stack, t_stack *info)
{
	while (stack->pre)
		stack = stack->pre;
	info->top = stack;
	while (stack->next)
		stack = stack->next;
	info->bottom = stack;
}