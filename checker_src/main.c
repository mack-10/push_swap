/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 05:51:45 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*move(char *line, t_stack *info)
{
	t_stack	*del;

	del = info;
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		move_s(info[0].top);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		move_s(info[1].top);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		info[0].top = move_r(info[0].top);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		info[1].top = move_r(info[1].top);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		info[0].top = move_rr(info[0].top);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		info[1].top = move_rr(info[1].top);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
	{
		info[0].top = move_rr(info[0].top);
		info[1].top = move_rr(info[1].top);
	}
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		move_p(&info[0].top, &info[1].top);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		move_p(&info[1].top, &info[0].top);
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
		info = move(line, info);
		free_once(&line);
	}
	free_once(&line);
	// print_sort(info);
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
	{t_node	*stack;
	t_stack	*info;
	char	**src;

	src = parsing(argc, argv);
	if (argc == 1)
		exit(0);
	stack = create_stack(src);
	if (argc == 2)
		free_double(&src);
	info = get_info_val(stack, NULL);
	read_lines(info);}
	// while (1);
	return (0);
}
