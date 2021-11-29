/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:54:58 by dait-atm          #+#    #+#             */
/*   Updated: 2021/11/29 02:33:46 by dait-atm         ###   ########.fr       */
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

#define MAP_CELLS		10000
#define VECTOR_CELLS	100000

#define __DEB(s) std::cerr<<s<<std::endl;

void	speed_map()
{
	ft::map<int, std::string> m;

	__DEB("insert ()");
	for (size_t i = 0; i < MAP_CELLS; ++i)
	{
		m.insert(ft::make_pair<int, std::string>(rand(), "🥷"));
	}
	__DEB("erase ()");
	for (auto im = m.begin(); im != m.end(); im = m.begin())
	{
		m.erase(im);
	}
}

void	speed_vector()
{
	ft::vector<int> v;

	__DEB("push_back()");
	for (size_t i = 0; i < VECTOR_CELLS; ++i)
		v.push_back(rand());
	__DEB("erase()");
	for (auto im = v.begin(); im != v.end(); im = v.begin())
		v.erase(im);
	
	// __DEB("push_back()");
	// for (size_t i = 0; i < VECTOR_CELLS; ++i)
	// 	v.push_back(rand());
	// __DEB("pop_back())");
	// for (size_t i = 0; i < VECTOR_CELLS; ++i)
	// 	v.pop_back();
}

int	main(void)
{
	srand(time(NULL));
	// speed_map();
	speed_vector();
	__DEB("done");
	return (0);
}
