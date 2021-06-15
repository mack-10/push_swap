C			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INC			=	-Iincludes
NAME		=	push_swap
SRC_PATH	=	srcs/
SRC_NAME	=	main.c				\
				get_next_line.c		\
				utils.c
SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_PATH	=	objs/
OBJ			=	$(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

LIB			=	libft

.PHONY : all clean fclean re mkdir

all : mkdir $(NAME)

mkdir :
	mkdir -p objs

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
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