# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 15:06:22 by bsantana          #+#    #+#              #
#    Updated: 2024/10/02 16:10:15 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WHITE := \033[1;37m
PINK := \033[1;35m  

NAME = ex01
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS_DIR = sources
SRCS = sources/main.cpp sources/Animal.cpp sources/Cat.cpp sources/Dog.cpp sources/WrongAnimal.cpp sources/WrongCat.cpp sources/Brain.cpp \
	   sources/tests.cpp

OBJS_DIR = objs
OBJS = $(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(WHITE)   Compiling files... "
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(PINK) Everything ready! 😉"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
