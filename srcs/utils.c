/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:58:08 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/04 07:14:56 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *s)
{
	write(2, s, ft_strlen(s));
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

// t_node	*find_top_bottom(char sign, t_node *stack)
// {
// 	if (sign == 't')
// 	{
// 		while (stack->pre)
// 			stack = stack->pre;
// 		return (stack);
// 	}
// 	else
// 	{
// 		while (stack->next)
// 			stack = stack->next;
// 		return (stack);
// 	}
// }