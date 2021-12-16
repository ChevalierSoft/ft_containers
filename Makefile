# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 12:55:09 by dait-atm          #+#    #+#              #
#    Updated: 2021/12/16 17:23:56 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTNAME	= ft.out
STDNAME	= std.out

FLAGS	= -std=c++98
FLAGS	+= -Wall -Wextra -Werror
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

all : ft

$(FTNAME) : ft
$(STDNAME) : std

ft:
	$(CC) $(FLAGS) -o $(FTNAME) $(SRCS)

std:
	$(CC) $(FLAGS) -o $(STDNAME) $(SRCS) -DORIGINAL=1

clean :
	$(RM) *.o
	$(RM) *.hpp.gch

fclean : clean
	$(RM) $(FTNAME) $(STDNAME)

re : fclean all

.PHONY : all ft std $(FTNAME) $(STDNAME) clean fclean re
