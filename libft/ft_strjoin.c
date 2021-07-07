/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:07:48 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/07 22:59:55 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_str;

	if (!s1 || !s2)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}
