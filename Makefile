# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 23:13:41 by sujeon            #+#    #+#              #
#    Updated: 2021/07/06 02:47:39 by sujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INC			=	-Iincludes
NAME		=	push_swap
SRC_PATH	=	srcs/
SRC_NAME	=	main.c				\
				utils.c				\
				linked_list.c		\
				parsing.c			\
				push_swap.c			\
				sort_under_five.c	\
				operation.c			\
				del.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_PATH	=	objs/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

LIB			=	libft

.PHONY : all clean fclean re mkdir

all : $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	mkdir -p objs
	$(C) $(CFLAG) $(INC) -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(LIB)
	$(C) $(CFLAG) $^ -Llibft -lft -o $@

clean :
	make clean -C $(LIB)
	rm -rf objs

fclean : clean
	make fclean -C $(LIB)
	rm push_swap

re : fclean all