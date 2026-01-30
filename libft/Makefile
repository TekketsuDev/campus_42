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
NAME     = libft.a
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
INCLUDES = include

SRC_DIR  = src
OBJ_DIR  = obj

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
       ft_memcpy.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
       ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	     ft_substr.c ft_tolower.c ft_toupper.c ft_memmove.c ft_strjoin.c \
	     ft_strtrim.c ft_split.c

# Bonus sources
# B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
#          ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
#          ft_lstmap.c

SRCS     := $(addprefix $(SRC_DIR)/,$(SRCS))
B_SRCS   := $(addprefix $(SRC_DIR)/,$(B_SRCS))

OBJECTS  := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
B_OBJECTS:= $(B_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $^
	ranlib $@

bonus: $(OBJECTS) $(B_OBJECTS)
	ar -rc $(NAME) $^
	ranlib $(NAME)

so: $(OBJECTS) $(B_OBJECTS)
	$(CC) -shared -o libft.so $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -fPIC -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re bonus so

