RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m # No Color

SRC = \
	libft/ft_striteri.c \
	libft/ft_itoa.c \
	libft/ft_memset.c \
	libft/ft_bzero.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_calloc.c \
	libft/ft_strlen.c \
	libft/ft_strlcpy.c \
	libft/ft_strlcat.c \
	libft/ft_strchr.c \
	libft/ft_strrchr.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strdup.c \
	libft/ft_isdigit.c \
	libft/ft_atoi.c \
	libft/ft_isalpha.c \
	libft/ft_isalnum.c \
	libft/ft_isascii.c \
	libft/ft_isprint.c \
	libft/ft_toupper.c \
	libft/ft_tolower.c \
	libft/ft_substr.c \
	libft/ft_strtrim.c \
	libft/ft_split.c \
	libft/ft_strmapi.c \
	libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	printf/ft_printf.c \
	printf/ft_putchar.c \
	printf/ft_putnbr_base.c \
	printf/ft_putnbr.c \
	printf/ft_putstr.c \
	printf/functions.c \
	printf/the_unsigned_thing.c \
	printf/printaddress.c \
	getnextline/get_next_line.c \
	getnextline/get_next_line_utils.c

NAME = libft.a

RM = rm

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "${GREEN}Compiling...${NC}"
	@$(AR) $(NAME) $(OBJ) > /dev/null 2>&1
	@echo "${GREEN}Finished compilation.${NC}"

fclean : clean
	@$(RM) -f $(NAME)

clean :
	@$(RM) -f $(OBJ)

re : fclean all
