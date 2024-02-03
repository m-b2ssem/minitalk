# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 17:55:58 by bmahdi            #+#    #+#              #
#    Updated: 2023/09/18 23:18:45 by bmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC := cc
FLAGS := -Wall -Wextra -Werror
DEPS = libft.h
NAME := libft.a

# List of source and object files
SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atoi.c

OBJS := $(SRCS:.c=.o)


# Default rule to make libft.a
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

# Compiling every source file into its object file
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	rm -f $(OBJS)

# Fclean rule to remove both object files and libft.a
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# With this setup, you can:
# - Compile all of libft by just typing 'make' or 'make all'.
# - Create test executables for specific functions, like 'make ft_strtrim'.
# - Clean object files with 'make clean'.
# - Remove both object files and libft.a with 'make fclean'.
# - Recompile everything with 'make re'.


