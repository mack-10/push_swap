/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:44:07 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 04:21:30 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parsing_int_min_max(int sign, char *s)
{
	int		len;
	char	*join;
	char	*tmp;
	int		i;

	if ((sign && (len = ft_strlen(s + 1)) > 10) ||
		(!sign && (len = ft_strlen(s)) > 10))
		error("Error: Over/Underflow\n");
	join = (char *)ft_calloc(10 - len, sizeof(char));
	i = -1;
	while (++i < 10 - len)
		ft_strlcpy(join + i, "0", 2);
	if (sign)
		tmp = ft_strjoin(join, s + 1);
	else
		tmp = ft_strjoin(join, s);
	s = tmp;
	if ((sign && ft_strncmp("2147483648", s, ft_strlen(s)) < 0) ||
		(!sign && ft_strncmp("2147483647", s, ft_strlen(s)) < 0))
		error("Error: Over/Underflow\n");
	free_once(join);
	free_once(s);
}

static void	parsing_num(char **s)
{
	int		i;
	int		j;
	int		sign;

	i = -1;
	while (s[++i])
	{
		// num or not
		if (s[i][0] == '-')
		{
			sign = 1;
			j = 1;
		}
		else
		{
			sign = 0;
			j = 0;
		}
		while ('0' <= s[i][j] && s[i][j] <= '9')
			j++;
		if (s[i][j])
			error("Error: Not valid argument\n");
		parsing_int_min_max(sign, s[i]);
	}
}

static void	parsing_duplicate(char **s1)
{
	int		i;
	int		j;
	char	**s2;

	s2 = s1;
	i = -1;
	while (s1[++i])
	{
		j = i;
		while (s2[++j])
		{
			printf("s1[%d]: %d, s2[%d]: %d\n", i, ft_atoi(s1[i]), j, ft_atoi(s2[j]));
			if (ft_atoi(s1[i]) == ft_atoi(s2[j]))
				error("Error: Duplicated arguments\n");
		}
	}
}

void		parsing(char **s)
{
	int		i;
	t_node	*lst;
	t_node	*first_node;

	parsing_num(s);
	parsing_duplicate(s);

	// linked list
	i = -1;
	while (s[++i])
	{
		if (!i)
		{
			lst = new_node(ft_atoi(s[i]));
			first_node = lst;
		}			
		else
			add_lst_node(&lst, ft_atoi(s[i]));
	}
	lst->next = first_node;
	first_node->pre = lst;
}