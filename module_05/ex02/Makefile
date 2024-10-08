# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 17:39:37 by bsantana          #+#    #+#              #
#    Updated: 2024/10/09 17:39:48 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WHITE := \033[1;37m
PINK := \033[1;35m  

NAME = ex03
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS = main.cpp sources/AMateria.cpp sources/Character.cpp sources/Cure.cpp sources/Ice.cpp sources/MateriaSource.cpp \
       tests.cpp tests/Gem.cpp tests/Future.cpp tests/Electro.cpp

OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(WHITE)   Compiling files... "
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(PINK) Everything ready! 😉"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: sources/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: tests/%.cpp | $(OBJS_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)/*.o
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
