/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:44:07 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 05:40:53 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_atoi(s1[i]) == ft_atoi(s2[j]))
				error();
		}
	}
}

static char	*len_under_10(int sign, int len, char *s)
{
	int		i;
	char	*join;
	char	*tmp;

	join = (char *)ft_calloc(10 - len, sizeof(char));
	i = -1;
	while (++i < 10 - len)
		ft_strlcpy(join + i, "0", 2);
	if (sign)
		tmp = ft_strjoin(join, s + 1);
	else
		tmp = ft_strjoin(join, s);
	free_once(&join);
	return (tmp);
}

static void	parsing_int_min_max(int sign, char *s)
{
	int		len;

	if (sign)
		len = ft_strlen(s + 1);
	else
		len = ft_strlen(s);
	if (len > 10)
		error();
	if (len < 10)
		s = len_under_10(sign, len, s);
	if ((sign && ft_strncmp("2147483648", s + 1, ft_strlen(s)) < 0)
		|| (!sign && ft_strncmp("2147483647", s, ft_strlen(s)) < 0))
		error();
	if (len < 10)
		free_once(&s);
}

static int	parsing_num(char *s)
{
	int		i;
	int		sign;

	sign = 0;
	if (s[0] == '-')
	{
		sign = 1;
		i = 1;
	}
	else
		i = 0;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	if (s[i])
		error();
	return (sign);
}

char	**parsing(int argc, char *argv[])
{
	int		i;
	int		sign;
	char	**src;

	if (argc == 2)
		src = ft_split(argv[1], ' ');
	else
		src = argv + 1;
	i = -1;
	while (src[++i])
	{
		sign = parsing_num(src[i]);
		parsing_int_min_max(sign, src[i]);
	}
	parsing_duplicate(src);
	return (src);
}
