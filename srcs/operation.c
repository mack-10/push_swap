/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:03:11 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/02 00:08:50 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_node *lst, t_node *pivot, char sign)
{
	int tmp;
	
	tmp = lst->num;
	lst->num = pivot->num;
	pivot->num = tmp;
	pivot = lst;
	if (sign == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void		rotate(t_node )