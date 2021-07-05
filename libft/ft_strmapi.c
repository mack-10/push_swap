/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:53:13 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 03:08:59 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		idx;

	idx = 0;
	if (!s)
		return (NULL);
	new_str = (char *)ft_calloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[idx])
	{
		new_str[idx] = f(idx, s[idx]);
		idx++;
	}
	new_str[idx] = 0;
	return (new_str);
}
