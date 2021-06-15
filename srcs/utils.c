/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:58:08 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 03:57:04 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(0);
}

void	free_once(char *s)
{
	free(s);
	s = NULL;
}

void	free_double(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}