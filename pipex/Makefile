# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fragamez <fragamez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 12:50:56 by fragamez          #+#    #+#              #
#    Updated: 2025/02/12 16:09:48 by fragamez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= libpipex.a

CFLAGS:= -g -Wall -Werror -Wextra \

LIBFT_DIR:= ./libft

LIBFT = $(LIBFT_DIR)/libft.a

HEADERS:= -I$(LIBFT_DIR)

SRCS =	./src/error.c\
	./src/get_paths.c\
	./src/pipex.c\
	./src/utils.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

libft:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@mv libft.a $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(HEADERS) $< -o $@

$(NAME): $(OBJS) libft
	@ar rcs $(NAME) $(OBJS)
	@echo "Pipex compiled"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT_DIR)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

pipillo: $(NAME)
	@$(CC) $(CFLAGS) ./src/main.c $(NAME) -o pipex

.PHONY: all, clean, fclean, re, libft
