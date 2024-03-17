SRC = \
	src/main.c \
	src/parse/free_double_array.c \
	src/parse/error_check.c \
	src/parse/error_check_utils.c \
	src/parse/add_to_stack.c

NAME = push_swap

RM = rm

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

libft :
	make -C libraries

$(NAME) : libft $(OBJ)
	$(CC) $(OBJ) -Llibraries -lft -o $(NAME)

fclean : clean
	@echo full cleaning of $(NAME) ...
	@$(RM) -f $(NAME)
	@make -C libraries fclean
	@sleep 0.5
	@echo $(NAME) cleaned.

clean :
	@echo cleaning $(NAME) ...
	@$(RM) -f $(OBJ)
	@make -C libraries clean
	@sleep 0.5
	@echo $(NAME) cleaned.

re : fclean all