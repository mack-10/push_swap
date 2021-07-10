# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 23:13:41 by sujeon            #+#    #+#              #
#    Updated: 2021/07/11 03:07:49 by sujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INC			=	-Iinclude
NAME		=	push_swap
SRC_PATH	=	src/
SRC_NAME	=	main.c				\
				parsing.c			\
				linked_list.c		\
				operation_1.c		\
				operation_2.c		\
				utils_1.c			\
				utils_2.c			\
				sort_4_5.c			\
				del.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

LIB			=	libft

.PHONY : all clean fclean re

all : $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(C) $(CFLAG) $(INC) -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(LIB)
	$(C) $(CFLAG) $^ -L$(LIB) -lft -o $@

clean :
	make clean -C $(LIB)
	rm -rf $(OBJ_PATH)

fclean : clean
	make fclean -C $(LIB)
	rm $(NAME)

re : fclean all