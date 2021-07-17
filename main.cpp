/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/17 05:45:58 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

#include "./vector/vector.hpp"

#include "./utils/color.h"
#include "./utils/ft_print_memory.h"

struct menfou
{
	int 		a;
	int			b;
	char		c;
	long long	d;
};

void	test_vector()
{
	ft::vector<int>				v;
	ft::vector<int>				w;
	ft::vector<char>			e;
	ft::vector<std::string>		st;

	std::cout <<std::endl<<CYN<< "__________________ft::vector__________________" <<RST<< std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "push_back()" <<RST<< std::endl;

	v.push_back(0x4C);
	v.push_back(0x55);
	v.push_back(0x4C);
	v.push_back(0x5A);
	for (auto & iv : v)
		std::cout << iv << " ";
	std::cout << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "pop_back()" <<RST<< std::endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();
	
	v.pop_back();
	v.pop_back();
	for (auto & iv : v)
		std::cout << iv << " ";
	std::cout << "(nothing should be printed)" << std::endl;

	v.push_back(0x4C);
	v.push_back(0x55);
	v.push_back(0x4C);
	v.push_back(0x5A);

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "copy constructor" <<RST<< std::endl;
	ft::vector<int>				c(w);
	ft_print_memory(reinterpret_cast<void *>(c._value_data), c._value_count * c._value_size);
	std::cout << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator =" <<RST<< std::endl;

	w = v;
	w.push_back('M');
	w.push_back('D');
	w.push_back('R');
	for (auto & iw : w)
		std::cout << iw << " ";
	std::cout << std::endl;
	ft_print_memory(reinterpret_cast<void *>(w._value_data), w._value_count * w._value_size);
	std::cout << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "empty()" <<RST<< std::endl;

	std::cout << "e : " << e.empty() << std::endl;
	e.push_back('v');
	std::cout << "e : " << e.empty() << std::endl;
	e.pop_back();
	std::cout << "e : " << e.empty() << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "max_size()" <<RST<< std::endl;

	std::vector<int>			maxv;
	std::vector<char>			maxc;
	std::vector<std::string>	maxs;
	std::vector<menfou>			mm;
	std::vector<short>			th;
	std::vector<long double>	ld;
	ft::vector<menfou>			mf;
	ft::vector<short>			sh;
	ft::vector<long double>		sd;

	std::cout << "char :    " << maxc.max_size() << "\tmine : " << e.max_size() << std::endl;
	std::cout << "short :   " << th.max_size() << "\tmine : " << sh.max_size() << std::endl;
	std::cout << "int :     " << maxv.max_size() << "\tmine : " << w.max_size() << std::endl;
	std::cout << "string :  " << maxs.max_size() << "\tmine : " << st.max_size() << std::endl;
	std::cout << "struct :  " << mm.max_size() << "\tmine : " << mf.max_size() << std::endl;
	std::cout << "l double :" << ld.max_size() << "\tmine : " << sd.max_size() << std::endl;


	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "size()" <<RST<< std::endl;

	std::cout << "v count : " << v.size() << std::endl;
	std::cout << "w count : " << w.size() << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "clear()" <<RST<< std::endl;
	w.clear();
	if (w.empty())
		std::cout << "empty" << std::endl;
	else
		std::cout << "full" << std::endl;

	// throw std::runtime_error("error test");
}

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    --n;
    while(n > 0) {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
        n -= 2;
    }
}

int	main(void)
{
	// test_vector();

	ft::vector<int> v;		//{1, 2, 3, 4, 5};

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

    my_reverse(v.begin(), v.end());
    for (int n : v) {
        std::cout << n << ' ';
    }


	return (0);
}
