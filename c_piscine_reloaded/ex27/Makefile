# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjamet-s <vjamet-s@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:53:27 by vjamet-s          #+#    #+#              #
#    Updated: 2025/12/18 18:53:30 by vjamet-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CFLAGS = -Wall -Wextra -Werror
SRC = ft_display_file.c
OBJ = ft_display_file.o

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	cc $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)


.PHONY: all clean fclean

