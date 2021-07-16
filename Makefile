# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 23:13:41 by sujeon            #+#    #+#              #
#    Updated: 2021/07/17 06:33:13 by sujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR

GREEN		=	"\033[32m"
BLUE		=	"\033[34m"
RESET		=	"\033[0m"

# COMPILE

C			=	gcc
CFLAG		=	-Wall -Wextra -Werror

# PUSH_SWAP

NAME		=	push_swap
INC			=	-Iinclude
SRC_PATH	=	src/
SRC_NAME	=	main.c				\
				parsing.c			\
				linked_list.c		\
				operation_1.c		\
				operation_2.c		\
				utils_1.c			\
				utils_2.c			\
				sort_4_5.c			\
				sort_over_5_1.c		\
				sort_over_5_2.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_PATH	=	obj/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))
LIB			=	libft

# CHECKER

CHECKER		=	checker
C_SRC_PATH	=	checker_src/
C_SRC_NAME	=	main.c				\
				parsing.c			\
				linked_list.c		\
				utils_1.c			\
				utils_2.c			\
				operation.c			\
				get_next_line.c
C_SRC		=	$(addprefix $(C_SRC_PATH), $(C_SRC_NAME))
C_OBJ_PATH	=	checker_obj/
C_OBJ		=	$(addprefix $(C_OBJ_PATH), $(C_SRC_NAME:.c=.o))

.PHONY : all clean fclean re

all : $(NAME) $(CHECKER)

# PUSH_SWAP

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(C) $(CFLAG) $(INC) -c $< -o $@



$(NAME) : $(OBJ)
	@echo "MAKING "$(BLUE)"LIBFT LIBRARY"$(RESET)
	@make -C $(LIB)
	@echo $(GREEN)"COMPLETE"$(RESET)
	@echo "MAKING "$(BLUE)"PUSH_SWAP"$(RESET)
	@$(C) $(CFLAG) $^ -L$(LIB) -lft -o $@
	@echo $(GREEN)"COMPLETE"$(RESET)

$(C_OBJ_PATH)%.o : $(C_SRC_PATH)%.c
	@mkdir -p $(C_OBJ_PATH)
	@$(C) $(CFLAG) $(INC) -c $< -o $@

$(CHECKER) : $(C_OBJ)
	@echo "MAKING "$(BLUE)"CHECKER"$(RESET)
	@$(C) $(CFLAG) $^ -L$(LIB) -lft -o $@
	@echo $(GREEN)"COMPLETE"$(RESET)

#

clean :
	@make clean -C $(LIB)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(C_OBJ_PATH)
	@echo $(GREEN)"CLEAN"$(RESET)


fclean : clean
	@make fclean -C $(LIB)
	@rm $(NAME)
	@rm $(CHECKER)
	@echo $(GREEN)"FCLEAN"$(RESET)

re : fclean all