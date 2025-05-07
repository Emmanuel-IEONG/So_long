# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eieong <eieong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 13:03:43 by eieong            #+#    #+#              #
#    Updated: 2025/03/17 14:55:51 by eieong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
LIBFT := libft/libft.a

RM := rm -rf
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
MLXFLAGS := -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES := -I/usr/include -I mlx

GREEN		:= \033[0;32m
LGREEN		:= \033[1;32m
PURPLE		:= \033[0;35m
LPURPLE		:= \033[1;35m

SRC :=	src/main.c \
		src/check_map.c \
		src/check_char.c \
		src/cleanup.c \
		src/image.c \
		src/moves.c \

SRC_BONUS :=	src_bonus/main_bonus.c \
				src_bonus/check_map_bonus.c \
				src_bonus/check_char_bonus.c \
				src_bonus/cleanup_bonus.c \
				src_bonus/image_bonus.c \
				src_bonus/moves_bonus.c \

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ)
	@echo "$(GREEN)----Compiling lib----"
	@make all -C libft
	@make all -C mlx
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $@
	@echo "\n$(LGREEN)So_long Compiled!\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

bonus: $(OBJ_BONUS)
	@echo "$(GREEN)----Compiling bonus lib----"
	@make all -C libft
	@make all -C mlx
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "\n$(LGREEN)So_long bonus Compiled!\n"

clean:
	@echo "$(PURPLE)----Cleaning----"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@make clean -C mlx
	@echo "\n$(LPURPLE)ALL CLEANED!\n"

re: fclean all

.PHONY: all clean fclean re
