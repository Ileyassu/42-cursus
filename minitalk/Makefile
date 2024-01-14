CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBRARY = libminitalk.a
SRC =	\
		functions/ft_memcpy.c \
		functions/ft_atoi.c \
		functions/ft_strlen.c \
		functions/ft_strdup.c \
		functions/ft_isdigit.c \
		printf/ft_printf.c \
		printf/ft_putchar.c \
		printf/ft_putnbr.c \
		printf/ft_putstr.c \
		printf/functions.c

OBJ = $(SRC:.c=.o)
SERVER_DIR = server
CLIENT_DIR = client

all: server client

server: $(SERVER_DIR)/server.c $(LIBRARY)
	$(CC) $(CFLAGS) -o $(SERVER_DIR)/server $(SERVER_DIR)/server.c -L. -lminitalk

client: $(CLIENT_DIR)/client.c $(LIBRARY)
	$(CC) $(CFLAGS) -o $(CLIENT_DIR)/client $(CLIENT_DIR)/client.c -L. -lminitalk

$(LIBRARY): $(OBJ)
	ar rcs $(LIBRARY) $(OBJ)

$(OBJ): %.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(SERVER_DIR)/server $(CLIENT_DIR)/client $(OBJ)

fclean: clean
	rm -f $(LIBRARY)
