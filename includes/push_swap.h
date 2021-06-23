/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:19:23 by sujeon            #+#    #+#             */
/*   Updated: 2021/06/23 23:27:43 by sujeon           ###   ########.fr       */
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

typedef struct s_node	t_node;
struct	s_node
{
	int		num;
	t_node	*pre;
	t_node	*next;
};

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}				t_stack;

t_node			*create_stack_a(char **s, t_stack *info);

/*
**	parsing.c
*/
void			parsing(char **s);

/*
**	push_swap.c
*/
void			push_swap(t_node *stack_a);

#endif
