/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:54:58 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/28 02:11:36 by dait-atm         ###   ########.fr       */
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

#define __DEB(s) std::cerr<<s<<std::endl;

void	speed_map()
{
	srand(time(NULL));
	ft::map<int, std::string> m;

	__DEB("insert ()");
	for (size_t i = 0; i < 10000; ++i)
	{
		m.insert(ft::make_pair<int, std::string>(rand(), "🥷"));
	}
	__DEB("erase ()");
	for (auto im = m.begin(); im != m.end(); im = m.begin())
	{
		m.erase(im);
	}
}

int	main(void)
{
	speed_map();
	__DEB("done");
	return (0);
}
