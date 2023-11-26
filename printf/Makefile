SRC = \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putnbr.c \
		ft_putstr.c \
		functions.c \
		the_unsigned_thing.c \
		printaddress.c

OBJ = $(SRC:.c=.o)

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a

all : $(NAME)

$(NAME) : $(OBJ) $(SRC)
	$(AR) $(NAME) $(OBJ)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -f $(OBJ) $(OBJ_BONUS)

re : fclean all