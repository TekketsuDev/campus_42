# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 09:05:38 by vjamet-s          #+#    #+#              #
#    Updated: 2026/02/04 09:08:05 by vjamet-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = get_next_line
CC = cc
HEADERS = get_next_line.h
CFLAGS = -Wall -Wextra -Werror
SRC = \
	get_next_line.c \
	ft_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
