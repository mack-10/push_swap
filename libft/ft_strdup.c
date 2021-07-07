/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:38:39 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/07 22:58:39 by sujeon           ###   ########.fr       */
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
	new_str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new_str)
		return (0);
	while (idx < size)
	{
		new_str[idx] = s[idx];
		idx++;
	}
	new_str[idx] = 0;
	return (new_str);
}
