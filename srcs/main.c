/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/05 04:35:57 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sort(t_node *stack_a, t_node *stack_b)
{
	// system("clear");

	int i = 0;
	printf("\nstack\n");
	printf("--------------------------\n");
	while (stack_a || stack_b)
	{
		printf("[%0d]\t|", i);
		if (stack_a)
		{
			printf("\t%d", stack_a->num);
			stack_a = stack_a->next;
		}
		else
			printf("\t");
		if (stack_b)
		{
			printf("\t%d", stack_b->num);
			stack_b = stack_b->next;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	print_info(t_stack *info)
{
	printf("\nstack info\n");
	printf("--------------------------\n");
	printf("size|\t%d\t%d\n", info[0].size, info[1].size);
	
	printf("top |");
	if (info[0].top)
		printf("\t%d", info[0].top->num);
	else
		printf("\t");
	if (info[1].top)
		printf("\t%d", info[1].top->num);
	printf("\n");
	
	printf("bot |");
	if (info[0].bot)
		printf("\t%d", info[0].bot->num);
	else
		printf("\t");
	if (info[1].bot)
		printf("\t%d\n", info[1].bot->num);
	else
		printf("\t\n");
	printf("--------------------------\n\n");
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

	info = (t_stack *)ft_calloc(2, sizeof(t_stack));
	get_info_val(&info, stack_a, NULL);
	// print_sort(stack_a, NULL);
	// print_info(info);
	
	push_swap(info, stack_a);
	if (argc == 2)
		free_double(src);
	// while (1);
	return (0);
}