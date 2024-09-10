# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:03:26 by mbecker           #+#    #+#              #
#    Updated: 2024/09/10 18:37:05 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBS =	-Llibft -lft \
		-Lminilibx-linux -lmlx_Linux \
		-lX11 -lXext \
		-lm

SRC =	src/parsing/parsing.c \
		src/parsing/elements.c \
		src/parsing/map.c \
		src/parsing/map_utils.c \
		src/draw.c \
		src/get_position.c \
		src/handle_destroy.c \
		src/handle_key.c \
		src/init.c \
		src/main.c \
		src/minimap.c \
		src/ray_casting.c 

all: $(NAME)

$(NAME): mlx libft
	@if [ ! -f $(NAME) ]; \
		then $(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBS);\
		if [ $$? -eq 0 ]; then\
			echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) ready.$(NC)";\
		else\
			echo "$(LRED)./$(RED)$(NAME)$(LRED) failed to compile.$(NC)";\
		fi;\
	else\
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) already compiled.$(NC)";\
	fi

clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode

fclean: clean
	@rm -rf $(NAME) minilibx-linux
	@make -C libft fclean
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

libft:
	@if [ ! -f libft/libft.a ]; then make -C ./libft all; fi

mlx:
	@if [ ! -d minilibx-linux ]; \
		then echo "$(LYELLOW)Downloading $(YELLOW)minilibx$(LYELLOW)...$(NC)"; \
		git clone https://github.com/42Paris/minilibx-linux.git >/dev/null 2>&1; \
	fi
	@if [ ! -f minilibx-linux/libmlx_Linux.a ];\
		then echo "$(LYELLOW)Compiling $(YELLOW)minilibx$(LYELLOW)...$(NC)"; \
		make -C ./minilibx-linux all >/dev/null 2>&1; \
	fi

.PHONY : all clean fclean re libft

RED =\033[1;31m
LRED =\033[0;31m
GREEN =\033[1;32m
LGREEN =\033[0;32m
YELLOW =\033[1;33m
LYELLOW =\033[0;33m
GREY =\033[1;37m
NC =\033[0m

test: clean
	@$(CC) $(CFLAGS) -o test test.c $(LIBS);\
