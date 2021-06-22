/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:19:23 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/16 20:43:56 by sujeon           ###   ########.fr       */
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
	struct t_node	*pre;
	struct t_node	*next;
}				t_node;

typedef struct	s_stack
{
	struct t_node	*top;
	struct t_node	*bottom;
}				t_stack;

t_node			*create_stack_a(char **s);

/*
**	parsing.c
*/
t_node			*parsing(char **s);

/*
**	push_swap.c
*/
void		push_swap(t_node *stack_a)

#endif
