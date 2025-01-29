# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eieong <eieong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 13:03:43 by eieong            #+#    #+#              #
#    Updated: 2025/01/29 16:34:07 by eieong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
LIBFT := libft/libft.a

RM := rm -rf
CC := cc
CFLAGS := -Wall -Wextra -Werror
MLXFLAGS := -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES := -I/usr/include -Imlx

SRC :=

OBJ := $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS)

all: $(NAME)

clean:

fclean: clean

re:

.PHONY: all clean fclean re
