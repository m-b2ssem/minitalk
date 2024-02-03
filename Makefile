# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 18:23:04 by bmahdi            #+#    #+#              #
#    Updated: 2024/02/03 00:34:23 by bmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = server.c client.c
LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o $(LIBFT)
	$(CC) $(CFLAGS) server.o $(LIBFT) -o $(SERVER)

$(CLIENT) : client.o $(LIBFT)
	$(CC) $(CFLAGS) client.o $(LIBFT) -o $(CLIENT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make -C ./libft

clean :
	@rm -f $(OBJ)
	@make -C ./libft clean

fclean : clean
	@rm -rf $(SERVER) $(CLIENT)
	@make -C ./libft fclean

re : fclean all