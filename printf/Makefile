# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 20:29:01 by ilyas             #+#    #+#              #
#    Updated: 2023/11/27 20:29:02 by ilyas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ) $(SRC)
	$(AR) $(NAME) $(OBJ)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -f $(OBJ) $(OBJ_BONUS)

re : fclean all