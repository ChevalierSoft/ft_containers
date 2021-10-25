# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 12:55:09 by dait-atm          #+#    #+#              #
#    Updated: 2021/10/25 02:44:46 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTNAME	= ft.out
STDNAME	= std.out

FLAGS	= -std=c++98
FLAGS	= #-Wall -Wextra -Werror
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

all : ft # std

$(FTNAME) : ft
$(STDNAME) : std

ft:
	$(CC) $(FLAGS) -o $(FTNAME) $(SRCS)

std:
	$(CC) $(FLAGS) -o $(STDNAME) $(SRCS) -DORIGINAL=1

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(FTNAME) $(STDNAME)

re : fclean all

.PHONY : all $(NAME) clean fclean re
