# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    speed.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 02:07:27 by dait-atm          #+#    #+#              #
#    Updated: 2021/11/19 02:07:33 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

g++ main_speed.cpp -o ft_speed.out
g++ main_speed.cpp -D ORIGINAL=1 -o std_speed.out
time ./ft_speed.out
time ./std_speed.out
rm ft_speed.out std_speed.out
