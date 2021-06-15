/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:18:49 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 00:01:59 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(0);
}

static void	parsing(int idx, char **s)
{
	int i;
	int j;

	i = -1;
	while (++i < idx)
	{
		if (s[i][0] == '-')
			j = 1;
		else
			j = 0;
		while ('0' <= s[i][j] && s[i][j] <= '9')
			j++;
		if (s[i][j])
			error("Error: Not formatted arguments\n");
		ft_atoi(s[i]);
	}
}

int			main(int argc, char *argv[])
{
	int		idx;
	char	**split;

	if (argc == 1)
		error("Error: No arguments\n");

	// argc == 2
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		idx = 0;
		while (split[idx])
			idx++;
		parsing(idx, split);
		free_double(split);
	}
	// argc > 2
	else
		parsing(argc - 1, argv + 1);
	return (0);
}