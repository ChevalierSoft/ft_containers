# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 12:55:09 by dait-atm          #+#    #+#              #
#    Updated: 2021/10/19 22:05:12 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTNAME	= ft.out
STDNAME	= std.out

FLAGS	= #-std=c++98
FLAGS	= -Wall -Wextra -Werror
FLAGS	+= -g #-fsanitize=address
SRCS	= main.cpp

ifeq ($(OS),Windows_NT)
	CC	= g++
	RM	= del
	FTNAME	= ft.exe
	STDNAME	= std.exe
else
	CC	= clang++
	RM	= rm -f
endif

all : ft std

$(FTNAME) : ft
$(STDNAME) : std

ft:
	$(CC) $(FLAGS) -DMINE=1 -o $(FTNAME) $(SRCS)

std:
	$(CC) $(FLAGS) -o $(STDNAME) $(SRCS)

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(FTNAME) $(STDNAME)

re : fclean all

.PHONY : all $(NAME) clean fclean re
