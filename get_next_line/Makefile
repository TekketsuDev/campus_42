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
SRC = get_next_line.c \
	get_next_line_utils.c \

OBJ = $(SRC:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
