/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:03:11 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/11 04:16:34 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int flag, t_node *stack)
{
	int	tmp;

	if (!stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (!flag)
		print("sa\n");
	else
		print("sb\n");
}

static t_node	*rotate_2(t_node *stack)
{
	t_node	*new;
	t_node	*del;

	if (!stack->next)
		return (stack);
	new = new_node(stack->num);
	del = stack;
	stack = stack->next;
	stack->pre = NULL;
	while (stack->next)
		stack = stack->next;
	stack->next = new;
	new->pre = stack;
	free(del);
	del = NULL;
	return (stack);
}

t_stack	*rotate_1(int flag, t_stack *tmp)
{
	t_stack	*info;
	t_node	*stack[2];

	stack[0] = tmp[0].top;
	stack[1] = tmp[1].top;
	if (!flag && stack[0]->next)
	{
		stack[0] = rotate_2(stack[0]);
		print("ra\n");
	}
	else if (flag == 1 && stack[1]->next)
	{
		stack[1] = rotate_2(stack[1]);
		print("rb\n");
	}
	else if (flag == 2 && stack[0]->next && stack[1]->next)
	{
		stack[0] = rotate_2(stack[0]);
		stack[1] = rotate_2(stack[1]);
		print("rr\n");
	}
	info = get_info_val(stack[0], stack[1]);
	free(tmp);
	tmp = NULL;
	return (info);
}

static t_node	*reverse_rotate_2(t_node *stack)
{
	t_node	*new;
	t_node	*del;

	if (!stack->next)
		return (NULL);
	stack = move_end(stack);
	del = stack;
	new = new_node(stack->num);
	stack = stack->pre;
	stack->next = NULL;
	stack = move_init(stack);
	stack->pre = new;
	new->next = stack;
	stack = new;
	free(del);
	del = NULL;
	return (stack);
}

t_stack	*reverse_rotate_1(int flag, t_stack *tmp)
{
	t_stack	*info;
	t_node	*stack[2];

	stack[0] = tmp[0].top;
	stack[1] = tmp[1].top;
	if (!flag && stack[0]->next)
	{
		stack[0] = reverse_rotate_2(stack[0]);
		print("rra\n");
	}
	else if (flag == 1 && stack[1]->next)
	{
		stack[1] = reverse_rotate_2(stack[1]);
		print("rrb\n");
	}
	else if (flag == 2 && stack[0]->next && stack[1]->next)
	{
		stack[0] = reverse_rotate_2(stack[0]);
		stack[1] = reverse_rotate_2(stack[1]);
		print("rrr\n");
	}
	info = get_info_val(stack[0], stack[1]);
	free(tmp);
	tmp = NULL;
	return (info);
}
