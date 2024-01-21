SRC = \
	so_long.c

NAME = so_long

RM = rm

OBJ = $(SRC:.c=.o)

MINILIBX = minilibx/libmlx.a

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