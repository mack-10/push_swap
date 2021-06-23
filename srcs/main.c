/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/23 23:33:55 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_node **stack)
{
	t_node	*stack_a;

	stack_a = *stack;
	// system("clear");

	// print
	int i = 1;
	printf("\t|\tA|\tB|\n");
	printf("--------------------------\n");
	while (stack_a)
	{
		// check top/ bottom
		// if (!stack_a->pre)
		// 	printf("bottom| %d\n", stack_a->num);
		// if (!stack_a->next)
		// 	printf("top| %d\n", stack_a->num);

		// check stack_a->num
		printf("[%0d]\t|\t%d|\n", i, stack_a->num);
		stack_a = stack_a->next;
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
		
	// push_swap(stack_a);
	print(&stack_a);
	// while (1);
	return (0);
}