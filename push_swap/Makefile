SRC = \
	src/main.c \
	src/parse/free_utils.c \
	src/parse/error_check.c \
	src/parse/error_check_utils.c \
	src/parse/add_to_stack.c \
	src/parse/is_sorted.c \
	src/rules/reverse_rotate.c \
	src/rules/operations.c \
	src/rules/push.c \
	src/rules/rotate.c \
	src/rules/swap.c \
	src/algorithms/sort_utils.c \
	src/algorithms/init_a_b_utils.c \
	src/algorithms/init_a.c \
	src/algorithms/init_b.c \
	src/algorithms/move_to_stacks.c \
	src/algorithms/sort_three.c \
	src/algorithms/sort.c

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