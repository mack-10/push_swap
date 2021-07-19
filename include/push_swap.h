/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:19:23 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/17 23:33:22 by sujeon           ###   ########.fr       */
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
t_stack	*stack_a(t_stack *info, int n);
t_stack	*stack_b(t_stack *info, int n);
void	set_stack(t_stack **info, int ra, int rb);
void	find_pivot(int flag, int pivot[], t_node *stack, int n);

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
int		reverse_check_sort(t_node *stack);
t_node	*move_init(t_node *stack);
t_node	*move_end(t_node *stack);
void	del_list(t_node *stack);

#endif
