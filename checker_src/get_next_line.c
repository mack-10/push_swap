/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:04:56 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 06:25:06 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*g_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;

	s = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;	
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = 0;
	return (s);
}

int get_next_line(char **line)
{
	char	buf[2];
	char	*s;
	char	*temp;
	int 	i, ret;

	i = 0;
	while (i < 2)
		buf[i++] = 0;
	s = g_strjoin("", "");
	while ((ret = read(0, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			break ;
		temp = g_strjoin(s, buf);
		free(s);
		s = temp;
	}
	*line = s;
	return (ret);
}
