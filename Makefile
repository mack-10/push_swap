# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 23:13:41 by sujeon            #+#    #+#              #
#    Updated: 2021/07/08 04:24:32 by sujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C			=	gcc
CFLAG		=	-Wall -Wextra -Werror -fsanitize=address
INC			=	-Iincludes
NAME		=	push_swap
SRC_PATH	=	src/
SRC_NAME	=	main.c				\
				utils_1.c			\
				utils_2.c			\
				linked_list.c		\
				parsing.c			\
				push_swap.c			\
				sort_under_5.c		\
				sort_over_5.c		\
				operation.c			\
				del.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

LIB			=	libft

.PHONY : all clean fclean re mkdir

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