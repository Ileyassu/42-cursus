
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m

SRC =	\
	so_long.c \
	src/ft_memcpy.c \
	src/ft_memset.c \
	src/ft_split.c \
	src/extract_ber.c \
	src/map_to_window.c \
	src/move.c \
	src/ft_key_hook.c \
	src/ft_strstr.c \
	src/flood_fill.c \
	getnextline/get_next_line.c \
	getnextline/get_next_line_utils.c \
	printf/ft_printf.c \
	printf/ft_putchar.c \
	printf/ft_putnbr_base.c \
	printf/ft_putnbr.c \
	printf/ft_putstr.c \
	printf/functions.c \
	printf/printaddress.c \
	printf/the_unsigned_thing.c

NAME = so_long

RM = rm

OBJ = $(SRC:.c=.o)

MINILIBX = mlx/libmlx.a

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all : $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN) compiling $(NAME) ... $(NC)"
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(RED) $(NAME) compiled successfully. $(NC)"

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

fclean : clean
	@echo full cleaning of $(NAME) ...
	@$(RM) -f $(NAME)
	@sleep 0.5
	@echo $(NAME) cleaned.

clean :
	@echo cleaning $(NAME) ...
	@$(RM) -f $(OBJ)
	@sleep 0.5
	@echo $(NAME) cleaned.

re : fclean all
