/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:19:23 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 03:57:20 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
**	HEADER
*/

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# include <stdio.h>

/*
**	FUNCTION
*/

/*
**	get_next_line.c
*/
int				get_next_line(char **line);
char			*g_strjoin(char *s1, char *s2);

/*
**	utils.c
*/
void			error(char *s);
void			free_once(char *s);
void			free_double(char **s);

/*
**	linked_list.c
*/

typedef struct	s_node
{
	int				num;
	struct s_node	*pre;
	struct s_node	*next;
}				t_node;
t_node			*new_node(int num);
void			add_lst_node(t_node **lst, int num);

/*
**	parsing.c
*/
void			parsing(char **s);

#endif