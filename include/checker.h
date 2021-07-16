/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 03:33:28 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 06:46:45 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
**	HEADER
*/

# include "push_swap.h"

/*
**	get_next_line.c
*/

int		get_next_line(char **line);

/*
**	operation.c
*/

void	move_s(t_node *stack);
t_node	*move_r(t_node *stack);
t_node	*move_rr(t_node *stack);
void	move_p(t_node **push, t_node **pop);

// del.c
void	print_sort(t_stack *info);

#endif