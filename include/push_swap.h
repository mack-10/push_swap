/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:19:23 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/11 03:46:27 by sujeon           ###   ########.fr       */
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
**	parsing.c
*/
char	**parsing(int argc, char *argv[]);

/*
**	linked_list.c
*/

t_node	*new_node(int num);
t_node	*create_stack(char **src);
t_stack	*create_info(t_node *stack);

/*
**	sort_*.c
*/
void	sort_4_5(t_stack *info);
void	sort_over_5(t_stack *info);

/*
**	operation.c
*/
void	swap(int flag, t_node *stack);
t_stack	*rotate_1(int flag, t_stack *tmp);
t_stack	*reverse_rotate_1(int flag, t_stack *tmp);
t_stack	*push_a(t_stack *tmp);
t_stack	*push_b(t_stack *tmp);

/*
**	utils.c
*/
void	error(void);
int		print(char *s);
void	free_once(char **s);
void	free_double(char ***s);
t_stack	*get_info_val(t_node *stack1, t_node *stack2);
int		check_sort(t_node *stack);
t_node	*move_init(t_node *stack);
t_node	*move_end(t_node *stack);
void	del_list(t_node *stack);

// DELETE
void	print_sort(t_stack *info);
void	print_info(t_stack *info);

#endif
