# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    speed.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 02:07:27 by dait-atm          #+#    #+#              #
#    Updated: 2021/12/16 16:58:50 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

g++ main_speed.cpp -o ft_speed.out
g++ main_speed.cpp -D ORIGINAL=1 -o std_speed.out
./ft_speed.out > logs/ft_speed.log
./std_speed.out > logs/std_speed.log
diff ./logs/ft_speed.log ./logs/std_speed.log
rm ft_speed.out std_speed.out
