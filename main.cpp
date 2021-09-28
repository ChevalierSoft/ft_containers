/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/09/28 06:02:34 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <map>

#include "./vector/vector.hpp"

#include "./utils/color.h"
#include "./utils/ft_print_memory.h"

// #include "iterator/random_access_iterator.hpp"

// _____________________________________________________________________________
class	menfou
{
private:
	static int	_nb;
public:
	int 		a;
	int			b;
	char		c;
	size_t		d;

	menfou() : a(1), b(42), c('A' + _nb), d(-1) { ++_nb; }
	~menfou() { std::cout << "~menfou" << std::endl;	}
};
int		menfou::_nb = 0;
std::ostream &	operator<< (std::ostream & o, const menfou & m) { o << "menfou : " << m.c << std::endl;	return o; }

// _____________________________________________________________________________
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
	std::cout <<std::endl<<CYN<< "contructor by copy" <<RST<< std::endl;
	{
		ft::vector<int>				ww(v);
		// v[0] = '0';
		v.push_back(48);
		for (auto & iv : ww)
			std::cout << iv << " ";
		std::cout << std::endl;
		ft::vector<int>				c(ww);
		ft_print_memory(reinterpret_cast<void *>(c._value_data), c._value_count * c._value_size);
		std::cout << std::endl;
		v.pop_back();
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator=" <<RST<< std::endl;
	{
		ft::vector<int>	ww(v);
		w.pop_back();
		ww = v;
		for (auto & iv : ww)
			std::cout << iv << " ";
		std::cout << std::endl;

	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "pop_back()" <<RST<< std::endl;
	{

		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();		
		v.pop_back();		// one more
		for (auto & iv : v)
			std::cout << iv << " ";
		std::cout << "(nothing should be printed)" << std::endl;
		v.push_back(0x4C);
		v.push_back(0x55);
		v.push_back(0x4C);
		v.push_back(0x5A);
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator=" <<RST<< std::endl;
	{
		w = v;
		w.push_back('M');
		w.push_back('D');
		w.push_back('R');
		std::cout << std::endl << "mine             ";
		for (auto & iw : w)
			std::cout << iw << " ";
		std::cout << std::endl << "should be        76 85 76 90 77 68 82"<< std::endl;
		ft_print_memory(reinterpret_cast<void *>(w._value_data), w._value_count * w._value_size);
		std::cout << std::endl;
	}
	

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "empty()" <<RST<< std::endl;
	{
		std::cout << "e : " << e.empty() <<" (should be 1)"<< std::endl;
		e.push_back('v');
		std::cout << "e : " << e.empty() <<" (should be 0)"<< std::endl;
		e.pop_back();
		std::cout << "e : " << e.empty() <<" (should be 1)"<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "max_size()" <<RST<< std::endl;
	{
		std::vector<int>			maxv;
		std::vector<char>			maxc;
		std::vector<std::string>	maxs;
		std::vector<menfou>			mm;
		std::vector<short>			th;
		std::vector<long double>	ld;
		ft::vector<menfou>			mf;
		ft::vector<short>			sh;
		ft::vector<long double>		sd;

		std::cout << "char     : " << maxc.max_size()	<< "\tmine : " << e.max_size() << std::endl;
		std::cout << "short    : " << th.max_size()		<< "\tmine : " << sh.max_size() << std::endl;
		std::cout << "int      : " << maxv.max_size()	<< "\tmine : " << w.max_size() << std::endl;
		std::cout << "string   : " << maxs.max_size()	<< "\tmine : " << st.max_size() << std::endl;
		std::cout << "struct   : " << mm.max_size()		<< "\tmine : " << mf.max_size() << std::endl;
		std::cout << "l double : " << ld.max_size()		<< "\tmine : " << sd.max_size() << std::endl;
	}


	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "size()" <<RST<< std::endl;
	{
		std::cout << "v count : " << v.size() << std::endl;
		std::cout << "w count : " << w.size() << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "clear()" <<RST<< std::endl;
	{
		if (w.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "full" << std::endl;
		w.clear();
		if (w.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "full" << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "at()" <<RST<< std::endl;
	{
		const ft::vector<int> cc(v);

		try
		{
			int &qwe = v.at(16);
			std::cout << "v.at(16) : " << (char)qwe << std::endl;
		}
		catch(const std::exception& e) {	std::cerr << e.what() << '\n';	}
		try
		{
			const int qwe = cc.at(1);
			std::cout << "cc.at(2) : " << (char)qwe << std::endl;
		}
		catch(const std::exception& e) {	std::cerr << e.what() << '\n';	}
	}
	
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "non member functions" <<RST<< std::endl;
	{
		v.clear();
		w.clear();
		v.push_back(0x4C); v.push_back(0x55); v.push_back(0x4C);
		w.push_back(0x4C); w.push_back(0x55); //w.push_back(0x4C);
		w = v;

		if (v == w)	std::cout << "== working"<< std::endl;
		else		std::cout<<RED<< "== NOT working" <<RST<<std::endl;
		if (v != w)	std::cout<<RED<< "!= NOT working" <<RST<<std::endl;
		else		std::cout << "!= working"<< std::endl;
		v.push_back('Z');
		if (v == w)	std::cout<<RED<< "== NOT working" <<RST<<std::endl;
		else		std::cout << "== working"<< std::endl;
		if (v != w)	std::cout << "!= working"<< std::endl;
		else		std::cout<<RED<< "!= NOT working" <<RST<<std::endl;

		if (w < v)	std::cout << "> working"<< std::endl;
		else		std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		if (v < w)	std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		else		std::cout << "> working"<< std::endl;

		if (v > w)	std::cout << "> working"<< std::endl;
		else		std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		if (w > v)	std::cout<<RED<< "> NOT working" <<RST<<std::endl;
		else		std::cout << "> working"<< std::endl;

		if (w <= v)	std::cout << "<= working"<< std::endl;
		else		std::cout<<RED<< "<= NOT working" <<RST<<std::endl;
		if (v <= w)	std::cout<<RED<< "<= NOT working" <<RST<<std::endl;
		else		std::cout << "<= working"<< std::endl;
		if (v >= w)	std::cout << ">= working"<< std::endl;
		else		std::cout<<RED<< ">= NOT working" <<RST<<std::endl;
		if (w >= v)	std::cout<<RED<< ">= NOT working" <<RST<<std::endl;
		else		std::cout << ">= working"<< std::endl;

		v.pop_back();
		if (v <= w)	std::cout << "<= working"<< std::endl;
		else		std::cout<<RED<< "<= NOT working" <<RST<<std::endl;
		if (w >= v)	std::cout << ">= working"<< std::endl;
		else		std::cout<<RED<< ">= NOT working" <<RST<<std::endl;

	}
	
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "memory" <<RST<< std::endl;
	{
		ft::vector<menfou> smf;

		menfou *mf = new menfou();
		smf.push_back(*mf);
		smf.pop_back();
		smf.clear();
		delete mf;					// without this line it should leak
	}

	//__________________________________________________________________________

}

// _____________________________________________________________________________
void	test_iterator_2(const ft::vector<char> &v)
{
	ft::vector<char>::const_reverse_iterator	ri = v.rbegin();

	while (ri != v.rend())
	{
		std::cout << *ri << "_";
		++ri;
	}
	std::cout << std::endl;
}

// _____________________________________________________________________________
void	test_iterator()
{
	ft::vector<char>							v;
	ft::vector<char>::const_reverse_iterator	cri;
	ft::vector<char>::reverse_iterator			ri;
	std::vector<char>							s;
	std::vector<char>::const_reverse_iterator	crs;
	std::vector<char>::reverse_iterator			rs;

	v.push_back('a'); v.push_back('b'); v.push_back('c'); v.push_back('d'); v.push_back('e');
	s.push_back('a'); s.push_back('b'); s.push_back('c'); s.push_back('d'); s.push_back('e');
	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "egualities with const_reverse_iterator and reverse_iterator" <<RST<< std::endl;
	{
		cri = v.rbegin();
		ri = v.rbegin();
		crs = s.rbegin();
		rs = s.rbegin();
		if (cri == ri)
			std::cout << "cri == ri" << std::endl;
		if (cri != ri)
			std::cout << "cri != ri" << std::endl;
		if (cri == cri)
			std::cout << "cri == cri" << std::endl;
		if (ri == ri)
			std::cout << "ri == ri" << std::endl;
		if (crs == rs)
			std::cout << "crs == rs" << std::endl;
		if (crs != rs)
			std::cout << "crs != rs" << std::endl;
		if (crs == crs)
			std::cout << "crs == crs" << std::endl;
		if (rs == rs)
			std::cout << "rs == rs" << std::endl;
	}

	// test_iterator_2(v);
	// test_iterator_2(s);

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "const_reverse_iterator" <<RST<< std::endl;
	{
		cri = v.rbegin();
		ri = v.rbegin();
		// ri = v.begin();			// possible in ft::, not possible in std::
		while (cri != v.rend())
		{
			std::cout << *cri << " ";
			++cri;
		}
		cri = v.rbegin();
		cri += 2;
		cri -= 1;
		std::cout << std::endl << *cri << std::endl;
		cri = ri;
		// ri = cri;
		std::cout << *cri << std::endl;
	}
	{
		crs = s.rbegin();
		rs = s.rbegin();
		while (crs != s.rend())
		{
			std::cout <<GRN<< *crs << " ";
			++crs;
		}
		crs = s.rbegin();
		crs += 2;
		crs -= 1;
		std::cout << std::endl << *crs << std::endl;
		crs = rs;
		// rs = crs;
		std::cout << *crs <<RST<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "testing the category" <<RST<< std::endl;
	{
		ft::iterator_traits<ft::vector<int>::iterator> tt;
		typedef ft::iterator_traits<int*> traits;
		if (typeid(traits::iterator_category)==typeid(ft::random_access_iterator_tag))
			std::cout <<GRN<< "int* is a random-access iterator" <<RST<< std::endl;
	}
	{
		std::iterator_traits<std::vector<int>::iterator> tt;
		typedef std::iterator_traits<int*> traits;
		if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
			std::cout << "int* is a random-access iterator" << std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "+ - * []" <<RST<< std::endl;
	{
		cri = v.rbegin();
		cri = cri + 3;
		std::cout << *cri << " ";
		cri = cri - 2;
		std::cout << *cri << " ";
		std::cout << cri[0] << cri[3] << cri[-1] << " ";
		std::cout << std::endl;
	}
	{
		crs = s.rbegin();
		crs = crs + 3;
		std::cout <<GRN<< *crs << " ";
		crs = crs - 2;
		std::cout << *crs << " ";
		std::cout << crs[0] << crs[3] << cri[-1] << " ";
		std::cout <<RST<< std::endl;
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "->" <<RST<< std::endl;
	{
		ft::vector<menfou>	vmf;
		ft::vector<menfou>::iterator imf;
		vmf.push_back(menfou());
		imf = vmf.begin();
		std::cout << imf->c << std::endl;
	}
	{
		std::cout <<GRN;
		std::vector<menfou>	vmf;
		std::vector<menfou>::iterator imf;
		vmf.push_back(menfou());
		imf = vmf.begin();
		std::cout <<GRN<< imf->c << std::endl;
	}

}

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    --n;
    while(n > 0) {
        typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
        n -= 2;
    }
}

int	main(void)
{
	test_iterator();

	test_vector();

	return (0);
}
