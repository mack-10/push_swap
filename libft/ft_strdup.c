/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:38:39 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 03:07:07 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		idx;
	char	*new_str;

	idx = 0;
	size = ft_strlen(s);
	new_str = (char *)ft_calloc(sizeof(char) * (size + 1));
	while (idx < size)
	{
		new_str[idx] = s[idx];
		idx++;
	}
	new_str[idx] = 0;
	return (new_str);
}
