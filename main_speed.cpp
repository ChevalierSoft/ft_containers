/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:54:58 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/16 17:11:18 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <chrono>
#include <ctime>
#ifdef ORIGINAL
	namespace ft = std;
	#include <map>
	#include <vector>
#else
	#include "map.hpp"
	#include "vector.hpp"
#endif

#define MAP_CELLS		1000000
#define VECTOR_CELLS	100000

#define __DEB(s) std::cout<<s<<std::endl;

class	menfou
{
private:
	static int	_nb;
public:
	int 		a;
	int			b;
	char		c;
	size_t		d;

	explicit	menfou() : a(1), b(42), c('A' + _nb), d(-1) { ++_nb; }
	explicit	menfou(char n_c) : a(1), b(42), c(n_c), d(-1) {}
	~menfou(){}
};
int		menfou::_nb = 0;
std::ostream &	operator<< (std::ostream & o, const menfou & m) { o << "obj : " << m.c << " " << m.b << std::endl;	return o; }

void	display_elapsed_time(	std::chrono::time_point<std::chrono::system_clock> start,
								std::chrono::time_point<std::chrono::system_clock> end )
{
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed : " << elapsed_seconds.count() << std::endl;
}

void	speed_map()
{
	//__________________________________________________________________________
	std::cout <<std::endl<< "___ speed_map ___" << std::endl;

	std::chrono::time_point<std::chrono::system_clock>	start;
	ft::map<int, std::string>							m;

	__DEB("insert ()");
	start = std::chrono::system_clock::now();
	{
		for (size_t i = 0; i < MAP_CELLS; ++i)
			m.insert(ft::make_pair<int, std::string>(rand(), "🥷"));
	}
	display_elapsed_time(start, std::chrono::system_clock::now());

	__DEB("erase ()");
	start = std::chrono::system_clock::now();
	{
		for (auto im = m.begin(); im != m.end(); im = m.begin())
			m.erase(im);
	}
	display_elapsed_time(start, std::chrono::system_clock::now());
}

void	speed_vector()
{
	//__________________________________________________________________________
	std::cout <<std::endl<< "___ speed_vector ___" << std::endl;

	ft::vector<menfou> v;
	std::chrono::time_point<std::chrono::system_clock> start;

	__DEB("push_back()");
	start = std::chrono::system_clock::now();
	{
		for (size_t i = 0; i < VECTOR_CELLS; ++i)
			v.push_back(menfou());
	}
	display_elapsed_time(start, std::chrono::system_clock::now());

	__DEB("erase()");
	start = std::chrono::system_clock::now();
	{
		for (auto im = v.begin(); im != v.end(); im = v.begin())
			v.erase(im);
	}
	display_elapsed_time(start, std::chrono::system_clock::now());
}

int	main(void)
{
	srand(time(NULL));
	speed_vector();
	speed_map();
	__DEB("done");
	return (0);
}
