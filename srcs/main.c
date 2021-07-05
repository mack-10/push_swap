/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 02:56:54 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_stack	*info;
	char	**src;

	if (argc == 1)
		error();
	src = parsing(argc, argv);
	stack_a = create_stack_a(src);
	info = (t_stack *)ft_calloc(2, sizeof(t_stack));
	get_info_val(&info, stack_a, NULL);
	push_swap(info, stack_a);
	if (argc == 2)
		free_double(src);
	return (0);
}
