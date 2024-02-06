SRC =	\
	so_long.c \
	src/ft_memcpy.c \
	src/ft_split.c \
	src/extract_ber.c \
	src/map_to_window.c \
	src/move.c \
	src/ft_key_hook.c \
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

MINILIBX = minilibx-linux/libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -Imlx -c $< -o $@

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -f $(OBJ)

re : fclean all