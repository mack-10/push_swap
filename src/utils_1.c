/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:58:08 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/11 04:13:38 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 5);
	exit(0);
}

int	print(char *s)
{
	static int	cnt;

	write(1, s, ft_strlen(s));
	cnt++;
	return (cnt);
}

void	free_once(char **s)
{
	free(*s);
	*s = NULL;
}

void	free_double(char ***s)
{
	int		i;
	char	**del;

	del = *s;
	i = -1;
	while (s[++i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

t_stack	*get_info_val(t_node *stack1, t_node *stack2)
{
	t_node	*stack;
	t_stack	*info;
	int		i;

	info = (t_stack *)ft_calloc(2, sizeof(t_stack));
	stack = stack1;
	i = -1;
	while (++i < 2)
	{
		if (i)
			stack = stack2;
		if (stack)
		{
			info[i].size = 1;
			stack = move_init(stack);
			info[i].top = stack;
			while (stack->next)
			{
				stack = stack->next;
				info[i].size++;
			}
			info[i].bot = stack;
		}
	}
	return (info);
}
