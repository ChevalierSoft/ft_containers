/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:54:58 by dait-atm          #+#    #+#             */
/*   Updated: 2021/12/03 03:38:37 by dait-atm         ###   ########.fr       */
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

#define MAP_CELLS		1000000
#define VECTOR_CELLS	100000

#define __DEB(s) std::cerr<<s<<std::endl;

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
	ft::vector<menfou> v;

	__DEB("push_back()");
	for (size_t i = 0; i < VECTOR_CELLS; ++i)
		v.push_back(menfou());

	__DEB("erase()");
	for (auto im = v.begin(); im != v.end(); im = v.begin())
		v.erase(im);
}

int	main(void)
{
	srand(time(NULL));
	// speed_vector();
	speed_map();
	__DEB("done");
	return (0);
}
