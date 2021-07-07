/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:19:23 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/08 05:41:14 by sujeon           ###   ########.fr       */
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

// DELETE
# include <stdio.h>
# define R "\x1b[31m"
# define G "\x1b[32m"
# define RESET "\x1b[0m"

static int cnt;
/*
**	STRUCT
*/

typedef struct s_node	t_node;
struct	s_node
{
	int		num;
	t_node	*pre;
	t_node	*next;
};

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}t_stack;

/*
**	FUNCTION
*/

/*
**	get_next_line.c
*/
int		get_next_line(char **line);
char	*g_strjoin(char *s1, char *s2);

/*
**	utils.c
*/
void	error(void);
void	print(char *s);
void	free_once(char *s);
void	free_double(char **s);
void	get_info_val(t_stack **info, t_node *stack_a, t_node *stack_b);
int		check_sort(t_node *stack, int flag);

/*
**	linked_list.c
*/

t_node	*new_node(int num);
t_node	*create_stack_a(char **src);
t_stack	*create_info(t_node *stack);

/*
**	parsing.c
*/
char	**parsing(int argc, char *argv[]);

/*
**	push_swap.c
*/
void	push_swap(t_stack *info);

/*
**	sort_under_five.c
*/
void	sort_under_5(t_stack *info);

/*
**	operation.c
*/
void	s(char sign, t_node *stack);
t_node	*r(char sign, t_stack *info);
t_node	*rr(char sign, t_stack *info);
void	p(char sign, t_node **push, t_node **pop);

/*
**	sort_over_five.c
*/
void	sort_over_5(t_stack *info);

// DELETE
void	print_sort(t_stack *info);
void	print_info(t_stack *info);


#endif
