/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:54:58 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/19 02:18:15 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef ORIGINAL
	namespace ft = std;
	#include <map>
	#include <vector>
#else
	#include "map.hpp"
	#include "vector.hpp"
#endif

void	speed_map()
{
	srand(time(NULL));
	ft::map<int, std::string> m;
	for (size_t i = 0; i < 1000000; ++i)
	{
		m.insert(ft::make_pair<int, std::string>(rand(), "🥷"));
	}
	for (auto im = m.begin(); im != m.end(); im = m.begin())
	{
		m.erase(im);
	}
	std::cout << "oui" << std::endl;
}

int	main(void)
{
	speed_map();
	return (0);
}
