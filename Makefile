# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbecker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:03:26 by mbecker           #+#    #+#              #
#    Updated: 2024/08/29 17:08:05 by mbecker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	main.c \
		safe_exit.c \
		parsing/parsing.c \
		parsing/elements.c

all: $(NAME)

$(NAME): libft
	@if [ ! -f $(NAME) ]; \
		then $(CC) $(CFLAGS) -o $(NAME) $(SRC) -Llibft -lft;\
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) ready.$(NC)";\
	else\
		echo "$(LGREEN)./$(GREEN)$(NAME)$(LGREEN) already compiled.$(NC)";\
	fi

clean:
	@echo "$(LRED)Removing objects and misc...$(NC)"
	@rm -rf *.out* */*.out testexe *.dSYM* .vscode

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)FULL CLEAN FINISHED$(NC)"

re: fclean all

libft:
	@if [ ! -f libft/libft.a ]; then make -C ./libft all; fi

mlx:
	@if [ ! -d minilibx-linux ]; \
		then echo "$(YELLOW)Downloading minilibx..."; \
		git clone https://github.com/42Paris/minilibx-linux.git >/dev/null 2>&1; \
	fi
	@if [ ! -f minilibx-linux/libmlx_Linux.a ];\
		then echo "$(YELLOW)Compiling minilibx..."; \
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
