/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/04 08:37:47 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sort(t_node *stack)
{
	// system("clear");

	int i = 0;
	printf("\nstack\n");
	printf("--------------------------\n");
	while (stack)
	{
		printf("[%0d]\t|\t%d|\n", i, stack->num);
		stack = stack->next;
		i++;
	}
	printf("\n");
}

int			main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_stack	*info;
	char	**src;

	if (argc == 1)
		error("Error: No arguments\n");

	src = parsing(argc, argv);
	stack_a = create_stack_a(src);
	info = create_info(stack_a);
	push_swap(info, stack_a);
	if (argc == 2)
		free_double(src);
	
	// while (1);
	return (0);
}