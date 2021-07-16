/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 06:46:18 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	move(char *line, t_stack **info)
{
	if (!ft_strncmp(line, "sa", 2))
		move_s((*info)[0].top);
	else if (!ft_strncmp(line, "sb", 2))
		move_s((*info)[1].top);
	else if (!ft_strncmp(line, "ra", 2))
		(*info)[0].top = move_r((*info)[0].top);
	else if (!ft_strncmp(line, "rb", 2))
		(*info)[1].top = move_r((*info)[1].top);
	else if (!ft_strncmp(line, "rra", 3))
		(*info)[0].top = move_rr((*info)[0].top);
	else if (!ft_strncmp(line, "rrb", 3))
		(*info)[1].top = move_rr((*info)[1].top);
	else if (!ft_strncmp(line, "rrr", 3))
	{
		(*info)[0].top = move_rr((*info)[0].top);
		(*info)[1].top = move_rr((*info)[1].top);
	}
	else if (!ft_strncmp(line, "pb", 2))
		move_p(&(*info)[0].top, &(*info)[1].top);
	else if (!ft_strncmp(line, "pa", 2))
		move_p(&(*info)[1].top, &(*info)[0].top);
}

static t_stack	*checker(char *line, t_stack *info)
{
	t_stack	*del;

	del = info;
	if (2 <= ft_strlen(line) && ft_strlen(line) <= 3)
		move(line, &info);
	else
		error();
	info = get_info_val(info[0].top, info[1].top);
	free(del);
	del = NULL;
	return (info);
}

static void	read_lines(t_stack *info)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		if (ft_strrchr(line, ' '))
			error();
		info = checker(line, info);
		free_once(&line);
	}
	free_once(&line);
	if (check_sort(info[0].top) && !info[1].top)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	del_list(info[0].top);
	free(info);
	info = NULL;
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
	read_lines(info);
	return (0);
}
