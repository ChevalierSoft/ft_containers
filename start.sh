# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 22:01:56 by dait-atm          #+#    #+#              #
#    Updated: 2021/12/04 04:57:44 by dait-atm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make ft
make std
mkdir -p logs
./ft.out > logs/ft.log
./std.out > logs/std.log
diff --color -c logs/ft.log logs/std.log
if [ $? -eq 0 ]
then
	echo "It Works Well 😇";
fi
rm -f logs/ft.log logs/std.log
