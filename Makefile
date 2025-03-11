# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eieong <eieong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 13:03:43 by eieong            #+#    #+#              #
#    Updated: 2025/03/11 10:58:30 by eieong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
LIBFT := libft/libft.a

RM := rm -rf
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
MLXFLAGS := -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES := -I/usr/include -Imlx

GREEN		:= \033[0;32m
LGREEN		:= \033[1;32m
PURPLE		:= \033[0;35m
LPURPLE		:= \033[1;35m

SRC :=	main.c \
		check_map.c \
		check_char.c \
		cleanup.c \

OBJ := $(SRC:.c=.o)

$(NAME):
	@echo "$(GREEN)----Compiling lib----"
	@make all -C libft
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $@
	@echo "\n$(LGREEN)So_long Compiled!\n"

all: $(NAME)

clean:
	@echo "$(PURPLE)----Cleaning----"
	@$(RM) $(OBJ)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@echo "\n$(LPURPLE)ALL CLEANED!\n"

re: fclean all

.PHONY: all clean fclean re
