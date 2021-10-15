/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/10/15 09:12:40 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <map>

#include "./vector/vector.hpp"

#include "./utils/color.h"
#include "./utils/ft_print_memory.h"

#define ENDL	std::cout<<std::endl;
#define __GRN	std::cout<<GRN;
#define __RST	std::cout<<RST;

#include "iterator/random_access_iterator.hpp"

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

	explicit menfou() : a(1), b(42), c('A' + _nb), d(-1) { ++_nb; }
	explicit menfou(char n_c) : a(1), b(42), c(n_c), d(-1) {}
	// ~menfou() { std::cout << "~menfou" << std::endl;	}
	~menfou(){}
};
int		menfou::_nb = 0;
std::ostream &	operator<< (std::ostream & o, const menfou & m) { o << "obj : " << m.c << std::endl;	return o; }

template <typename T>
void	display(T v)
{
	for (auto & iv : v)
		std::cout << iv;
	std::cout << std::endl;
}
template <typename T>
void	display(T v, char c)
{
	for (auto & iv : v)
		std::cout << iv << c;
	std::cout << std::endl;
}

// _____________________________________________________________________________
void	test_vector()
{
	ft::vector<int>				v;
	ft::vector<int>				w;
	ft::vector<char>			e;
	ft::vector<std::string>		st;
	std::string					strft;
	std::string					strstd;

	std::cout <<std::endl<<CYN<< "__________________ft::vector__________________" <<RST<< std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "push_back()" <<RST<< std::endl;

	v.push_back(0x4C);
	v.push_back(0x55);
	v.push_back(0x4C);
	v.push_back(0x5A);
	display(v, ' ');

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
		std::cout << "copied : " << c.size() << std::endl;
		v.pop_back();
	}

	std::cout <<std::endl<<CYN<< "contructor by range" <<RST<< std::endl;
	{
		ft::vector<menfou>	pif;
		pif.push_back(menfou('1'));
		pif.push_back(menfou('2'));
		pif.push_back(menfou('3'));
		pif.push_back(menfou('4'));
		pif.push_back(menfou('5'));

		ft::vector<menfou>	vrange(pif.begin() + 1, pif.end() - 1);
		display(vrange);
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
		std::cout << std::endl <<GRN<< "should be        76 85 76 90 77 68 82"<<RST<< std::endl;
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
		std::cout << "size : " << w.size() << std::endl;
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
	std::cout <<std::endl<<CYN<< "front(), back() and data()" <<RST<< std::endl;
	{
		ft::vector<menfou> sfm;
		menfou *mf = new menfou();
		sfm.push_back(*mf);
		sfm.push_back(menfou());
		ft::vector<menfou>::reference rsfm = sfm.front();
		std::cout << rsfm.b << std::endl;
		rsfm = sfm.back();					// by copy to be sure
		std::cout << rsfm.b << std::endl;
		ft::vector<menfou>::const_reference crsfm = sfm.front();
		std::cout << crsfm.b << std::endl;
		ft::vector<menfou>::const_reference crsfmb = sfm.back();
		std::cout << crsfmb.b << std::endl;
		delete mf;
	}
	{
		std::cout << std::endl << GRN;
		ft::vector<menfou> sfm;
		menfou *mf = new menfou();
		sfm.push_back(*mf);
		sfm.push_back(menfou());
		ft::vector<menfou>::reference rsfm = sfm.front();
		std::cout << rsfm.b << std::endl;
		rsfm = sfm.back();
		std::cout << rsfm.b << std::endl;
		ft::vector<menfou>::const_reference crsfm = sfm.front();
		std::cout << crsfm.b << std::endl;
		ft::vector<menfou>::const_reference crsfmb = sfm.back();
		std::cout << crsfmb.b << std::endl;
		delete mf;
	}
	std::cout << RST;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "reserve() without valgrind (remove comments)" <<RST<< std::endl;
	// {
	// 	ft::vector<menfou> rev;
	// 	try
	// 	{
	// 		rev.reserve(UINT32_MAX);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
	// {
	// 	ft::vector<menfou> rev;
	// 	try
	// 	{
	// 		rev.reserve(UINT32_MAX);
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr <<GRN<< e.what() <<RST<< '\n';
	// 	}
	// }

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator[]" <<RST<< std::endl;
	{
		ft::vector<menfou> ovh;
		for (int i = 0; i < 3; ++i)
			ovh.push_back(menfou('0' + i));
		std::cout << ovh[2] << ovh[0] << ovh[1];
		ft::vector<menfou>::const_reference crovh = ovh[0];
		std::cout << crovh;
		// std::cout << ovh[334] <<std::endl;	// should be a heap-buffer-overflow
	}
	{
		__GRN
		std::vector<menfou> ovh;
		for (int i = 0; i < 3; ++i)
			ovh.push_back(menfou('0' + i));
		std::cout << ovh[2] << ovh[0] << ovh[1];
		ft::vector<menfou>::const_reference crovh = ovh[0];
		std::cout << crovh;
		// std::cout << ovh[334] <<std::endl;	// should be a heap-buffer-overflow
		__RST
	}

	std::cout <<std::endl<<CYN<< "is_integral" <<RST<< std::endl;
	{
		std::cout << "char: \t" << ft::is_integral<char>::value << std::endl;
		std::cout << "int: \t" << ft::is_integral<int>::value << std::endl;
		std::cout << "float: \t" << ft::is_integral<float>::value << std::endl;
	}
	{
		__GRN
		std::cout << "char: \t" << std::is_integral<char>::value << std::endl;
		std::cout << "int: \t" << std::is_integral<int>::value << std::endl;
		std::cout << "float: \t" << std::is_integral<float>::value << std::endl;
		__RST
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "insert()" <<RST<< std::endl;
	{
		ft::vector<menfou>	asd;
		ft::vector<menfou>	cpy(16, menfou('x'));

		asd.push_back(menfou('a'));
		asd.insert(asd.begin(), menfou('b'));
		asd.insert(asd.end(), menfou('c'));
		asd.insert(asd.end(), menfou('d'));
		asd.insert(asd.end() - 2, menfou('e'));
		asd.insert(asd.end(), 3, menfou('f'));
		asd.insert(asd.begin(), 2, menfou('g'));
		asd.insert(asd.begin() + 2, 2, menfou('h'));
		asd.insert(asd.end() - 3, 24, menfou('i'));

		// g g h h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f
		asd.insert(asd.end(), asd.begin(), asd.begin() + 5);

			// for (auto & iasd : asd)
			// 	std::cout << iasd.c << " ";
			// std::cout << std::endl;
			// std::cout << "size : " << asd.size() << std::endl;

		// g g h h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b
		asd.insert(asd.begin() + 3, cpy.begin(), cpy.end());

		// g g h x x x x x x x x x x x x x x x x h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b
		asd.insert(asd.begin() + 3, asd.begin(), asd.end());
		// g g h g g h x x x x x x x x x x x x x x x x h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b x x x x x x x x x x x x x x x x h b a e c d i i i i i i i i i i i i i i i i i i i i i i i i f f f g g h h b
		asd.insert(asd.begin() + 6, asd.rbegin(), asd.rend());

		strft = "";
		for (auto & iasd : asd)
			strft += iasd.c;

		std::cout << "size : " << asd.size() << std::endl;

		ft::vector<int> jkl;
		jkl.insert(jkl.begin(), 7, 7);

	}
	{
		__GRN

		std::vector<menfou>	asd;
		std::vector<menfou>	cpy(16, menfou('x'));

		asd.push_back(menfou('a'));
		asd.insert(asd.begin(), menfou('b'));
		asd.insert(asd.end(), menfou('c'));
		asd.insert(asd.end(), menfou('d'));
		asd.insert(asd.end() - 2, menfou('e'));
		asd.insert(asd.end(), 3, menfou('f'));
		asd.insert(asd.begin(), 2, menfou('g'));
		asd.insert(asd.begin() + 2, 2, menfou('h'));
		asd.insert(asd.end() - 3, 24, menfou('i'));

		asd.insert(asd.end(), asd.begin(), asd.begin() + 5);
		asd.insert(asd.begin() + 3, cpy.begin(), cpy.end());
		asd.insert(asd.begin() + 3, asd.begin(), asd.end());
		asd.insert(asd.begin() + 6, asd.rbegin(), asd.rend());

		strstd = "";
		for (auto & iasd : asd)
			strstd += iasd.c;
		std::cout << "size : " << asd.size() << std::endl;

		std::vector<int> jkl;
		jkl.insert(jkl.begin(), 7, 7);
		__RST
	}
	if (strft != strstd)
		std::cout << "error" <<std::endl<< strft <<std::endl<<GRN<< strstd <<RST<<std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "assign()" <<RST<< std::endl;
	{
		ft::vector<int> jkl;
		ft::vector<int> uio;

		uio.insert(jkl.begin(), 7, 3);	// enable_if is working
		
		jkl.assign(3, 9);				//
		display(jkl);

		// try {	jkl.assign(-3, 7);	}
		// catch(const std::exception& e){	std::cerr << e.what() << '\n'; }
		
		jkl.assign(uio.begin(), uio.end());
		display(jkl);

	}
	{

		__GRN
		std::vector<int> jkl;
		std::vector<int> uio;

		uio.insert(jkl.begin(), 7, 3);	// enable_if is working
		
		jkl.assign(3, 9);				//
		display(jkl);

		// try {	jkl.assign(-3, 7);	}
		// catch(const std::exception& e){	std::cerr << e.what() << '\n'; }
		
		jkl.assign(uio.begin(), uio.end());
		display(jkl);
		__RST
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "erase()" <<RST<< std::endl;
	{
		// ? use vector's type in sizeof : https://stackoverflow.com/a/53259979
		ft::vector<int>	vv;
		// ft::vector<int>::iterator ivv;
		int rera;
		vv.push_back('L');
		vv.push_back('L');
		vv.push_back('U');
		vv.push_back('L');
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.erase(vv.begin());
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.erase(vv.end() - 1);
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.push_back('V');
		vv.push_back('U');
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.erase(vv.begin() + 2);
		vv.erase(vv.begin());
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.insert(vv.begin() + 1, 'W');
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.insert(vv.end(), vv.begin(), vv.end());
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL

		rera = vv.erase(vv.begin() + 1, vv.end() - 1) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		rera = vv.erase(vv.end(), vv.end()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		rera = vv.erase(vv.begin(), vv.begin()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		rera = vv.erase(vv.begin(), vv.end()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		ENDL
	}
	{
		__GRN
		std::vector<int> vv;
		int rera;
		vv.push_back('L');
		vv.push_back('L');
		vv.push_back('U');
		vv.push_back('L');
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.erase(vv.begin());
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.erase(vv.end() - 1);
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.push_back('V');
		vv.push_back('U');
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.erase(vv.begin() + 2);
		vv.erase(vv.begin());
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.insert(vv.begin() + 1, 'W');
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		vv.insert(vv.end(), vv.begin(), vv.end());
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL

		rera = vv.erase(vv.begin() + 1, vv.end() - 1) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		rera = vv.erase(vv.end(), vv.end()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		rera = vv.erase(vv.begin(), vv.begin()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		rera = vv.erase(vv.begin(), vv.end()) - vv.begin();
		std::cout << "rera : " << rera << std::endl;
		ft_print_memory((void *)vv.data(), vv.size() * sizeof(int)); ENDL
		ENDL
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "resize()" <<RST<< std::endl;
	{
		ft::vector<menfou> vres;
		vres.insert(vres.begin(), 6, menfou('r'));

		vres.resize(1);
		display(vres);
		// vres.resize(5);
		// display(vres);
		vres.resize(9, menfou('x'));
		display(vres);
	}
	{
		__GRN

		std::vector<menfou> vres;
		vres.insert(vres.begin(), 6, menfou('r'));

		vres.resize(1);
		display(vres);
		// vres.resize(5);				// ! needs to be compiled with -std=c++98
		// display(vres);
		vres.resize(9, menfou('x'));
		display(vres);

		__RST
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "swap()" <<RST<< std::endl;
	{
		ft::vector<menfou> vmf1;
		ft::vector<menfou> vmf2;

		vmf1.insert(vmf1.begin(), 3, menfou('1'));
		vmf2.insert(vmf2.begin(), 5, menfou('2'));

		vmf1.swap(vmf2);

		display(vmf1);
		display(vmf2);
	}
	{
		__GRN

		std::vector<menfou> vmf1;
		std::vector<menfou> vmf2;

		vmf1.insert(vmf1.begin(), 3, menfou('1'));
		vmf2.insert(vmf2.begin(), 5, menfou('2'));

		vmf1.swap(vmf2);

		display(vmf1);
		display(vmf2);

		__RST
	}

}	//__________________________________________________________________________


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
		vmf.push_back(menfou('c'));
		imf = vmf.begin();
		std::cout << imf->c << std::endl;
	}
	{
		__GRN
		std::vector<menfou>	vmf;
		std::vector<menfou>::iterator imf;
		vmf.push_back(menfou('c'));
		imf = vmf.begin();
		std::cout << imf->c << std::endl;
		__RST
	}

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "egualities const an not const" <<RST<< std::endl;
	{
		ft::vector<char>::const_iterator iv1 = v.begin();
		ft::vector<char>::const_iterator iv2(v.begin());
	}
	{
		std::vector<char>::const_iterator sv1 = s.begin();
		std::vector<char>::const_iterator sv2(s.begin());
	}
}

int	main(void)
{
	// test_iterator();
	// test_vector();

	std::vector<char>			v1(10, '1');
	std::vector<char>			v2(8, '2');
	ft::vector<char>			v3(10, '1');
	ft::vector<char>			v4(8, '2');
	int							err = 0;

	std::cout << "size : " << v2.size() <<" "<< v4.size() << std::endl;
	std::cout << "capacity : " << v2.capacity() <<" "<<  v4.capacity() << std::endl;
	display(v3);
	display(v1);

	v1.insert(v1.begin(), 2, 80);	// 50
	v3.insert(v3.begin(), 2, 80);
	// v1.push_back('p');v1.push_back('P');
	// v3.push_back('p');v3.push_back('P');

	// swap(v1, v2);
	// swap(v3, v4);

	std::cout << "size : " << v1.size() <<" "<< v3.size() << std::endl;
	std::cout << "capacity : " << v1.capacity() <<" "<<  v3.capacity() << std::endl;

	display(v1);
	display(v3);

	return (0);
}
