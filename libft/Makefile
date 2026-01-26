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
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = include

SRCS = src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c \
       src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_memchr.c src/ft_memcmp.c \
       src/ft_memcpy.c src/ft_memset.c src/ft_strchr.c src/ft_strdup.c src/ft_strlcat.c \
       src/ft_strlcpy.c src/ft_strlen.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c \
       src/ft_substr.c src/ft_tolower.c src/ft_toupper.c

#B_SRCS = src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c src/ft_lstlast.c \
         src/ft_lstadd_back.c src/ft_lstdelone.c src/ft_lstclear.c src/ft_lstiter.c \
         src/ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)
B_OBJECTS = $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus: $(OBJECTS) $(B_OBJECTS)
	ar -rc $(NAME) $(OBJECTS) $(B_OBJECTS)
	ranlib $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) -I$(INCLUDES) $(SRCS) $(B_SRCS)
	gcc -shared -o libft.so $(OBJECTS) $(B_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re bonus so

