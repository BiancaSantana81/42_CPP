# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 14:04:07 by bsantana          #+#    #+#              #
#    Updated: 2024/09/17 14:06:46 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WHITE := \033[1;37m
PINK := \033[1;35m  

NAME = ex00
CC = c++
FLAGS = -Werror -Wall -Wextra -std=c++98
MAKEFLAGS += --silent

SRCS = main.cpp \
	   Zombie.cpp newZombie.cpp randomChump.cpp
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

.PHONY: all clean fclean re run
