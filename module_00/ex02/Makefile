# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 14:42:24 by bsantana          #+#    #+#              #
#    Updated: 2024/09/03 14:43:17 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WHITE := \033[1;37m
PINK := \033[1;35m  

NAME =  dreams_job
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS = main.cpp megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(WHITE)   Compiling files... "
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(PINK) Everything ready! 😉"

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
