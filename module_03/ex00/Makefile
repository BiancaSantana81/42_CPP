# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 15:06:22 by bsantana          #+#    #+#              #
#    Updated: 2024/09/25 15:09:40 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WHITE := \033[1;37m
PINK := \033[1;35m  

NAME = ex00
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS = main.cpp ClapTrap.cpp

OBJS_DIR = objs
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(WHITE)   Compiling files... "
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(PINK) Everything ready! 😉"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
