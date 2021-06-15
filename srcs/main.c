/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 04:58:58 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	char	**split;
	t_node	*lst;

	if (argc == 1)
		error("Error: No arguments\n");

	// argc == 2
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		lst = parsing(split);
		free_double(split);
	}
	// argc > 2
	else
		lst = parsing(argv + 1);
	
	int i = 0;
	while (++i < argc)
	{
		printf("[%d]lst->num | %d\n", i, lst->num);
		lst = lst->next;
	}
	
	// while (1);
	return (0);
}