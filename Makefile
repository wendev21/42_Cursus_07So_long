# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2024/04/03 12:32:06 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES = so_long.c \
		  initiation_struct.c \
		  map_mangment.c \
		  handle_errors.c \
		  handle_utlis.c \
		  flood_fill.c \
		  check_mnlx.c \
		  ft_mnlx.c

LIBFT = ./Libft/libft.a
OBJS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

start:
	@make all

$(LIBFT):
	@make -C ./Libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: start all clean fclean re #bonus
