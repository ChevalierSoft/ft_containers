# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 12:55:09 by dait-atm          #+#    #+#              #
#    Updated: 2021/10/06 09:45:49 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= a.out
FLAGS	= #-std=c++98 #-Wall -Wextra -Werror
FLAGS	+= -g #-fsanitize=address
SRCS	= main.cpp

ifeq ($(OS),Windows_NT)
	CC	= g++
	NAME= a.exe
else
	CC	= clang++
endif

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all $(NAME) clean fclean re
