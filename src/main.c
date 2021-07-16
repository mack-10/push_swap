/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 06:48:43 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_over_5(t_stack *info)
{
	info = stack_a(info, info[0].size);
	del_list(info[0].top);
	free(info);
	info = NULL;
}

static void	sort_3(t_stack *info)
{
	while (!check_sort(info[0].top))
	{
		if (info[0].top->num > info[0].bot->num)
			info = rotate_1(0, info);
		else
			swap(0, info[0].top);
	}
	del_list(info[0].top);
	free(info);
	info = NULL;
}

static void	push_swap(t_stack *info)
{	
	if (check_sort(info[0].top))
		exit(0);
	if (info->size == 3)
		sort_3(info);
	else if (info->size == 4 || info->size == 5)
		sort_4_5(info);
	else
		sort_over_5(info);
}

int	main(int argc, char *argv[])
{
	t_node	*stack;
	t_stack	*info;
	char	**src;

	src = parsing(argc, argv);
	if (argc == 1)
		exit(0);
	stack = create_stack(src);
	if (argc == 2)
		free_double(&src);
	info = get_info_val(stack, NULL);
	push_swap(info);
	printf("%d\n", print("") - 1);
	return (0);
}
