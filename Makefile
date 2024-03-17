# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2024/03/16 14:48:21 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES = so_long.c \
		  initiation_struct.c \
		  map_mangment.c \
		  handle_errors.c \
		  flood_fill.c 
LIBFT = ./Libft/libft.a
OBJS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

start:
	@make all

$(LIBFT):
	@make -C ./Libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re #bonus
