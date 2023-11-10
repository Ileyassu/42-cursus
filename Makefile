SRC = \
	./ft_itoi.c \
	./ft_striteri.c \
	./ft_memset.c \
	./ft_bzero.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_calloc.c \
	./ft_strlen.c \
	./ft_strlcpy.c \
	./ft_strlcat.c \
	./ft_strchr.c \
	./ft_strrchr.c \
	./ft_strncmp.c \
	./ft_strnstr.c \
	./ft_strdup.c \
	./ft_isdigit.c \
	./ft_atoi.c \
	./ft_isalpha.c \
	./ft_isalnum.c \
	./ft_isascii.c \
	./ft_isprint.c \
	./ft_toupper.c \
	./ft_tolower.c \
	./ft_substr.c \
	./ft_strjoin.c \
	./ft_strtrim.c \
	./ft_split.c \
	./ft_strmapi.c \
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c
NAME = libft.a
RM = rm

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)	
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

fclean :
	$(RM) $(OBJ) $(NAME)

clean :
	$(RM) $(OBJ)

re : fclean all