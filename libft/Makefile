SRC = \
	ft_striteri.c \
	ft_itoa.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strdup.c \
	ft_isdigit.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SRC_BONUS =	\
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstadd_back.c

NAME = libft.a

RM = rm

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)


CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all : $(NAME)

bonus : $(OBJ_BONUS)	
	$(AR) $(NAME) $(OBJ_BONUS)

$(NAME) : $(OBJ)	
	$(AR) $(NAME) $(OBJ)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -f $(OBJ) $(OBJ_BONUS)

re : fclean all
