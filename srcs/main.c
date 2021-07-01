/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/02 00:00:16 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_node *stack)
{
	// system("clear");

	int i = 0;
	printf("\n\t|\tA|\tB|\n");
	printf("--------------------------\n");
	while (stack)
	{
		printf("[%0d]\t|\t%d|\n", i, stack->num);
		stack = stack->next;
		i++;
	}
}

int			main(int argc, char *argv[])
{
	char	**split;
	t_node	*stack_a;
	t_stack	*info;

	// 예외
	if (argc == 1)
		error("Error: No arguments\n");

	info = ft_calloc(1, sizeof(t_stack));

	// argc == 2
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		parsing(split);
		stack_a = create_stack_a(split, info);
		free_double(split);
	}
	// argc > 2
	else
	{
		parsing(argv + 1);
		stack_a = create_stack_a(argv + 1, info);
	}
		
	push_swap(info, stack_a);
	
	// while (1);
	return (0);
}