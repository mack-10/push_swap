/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:09:19 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 03:06:22 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)s + idx);
	return (0);
}
